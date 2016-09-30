function Aest = solver(imageSize, queryLimit)

maxRegions = queryLimit;
regionIdx = ones(imageSize, 'uint32');
regionDims = zeros(4, maxRegions, 'single');
regionSize = zeros(maxRegions, 1, 'single');
regionSum = zeros(maxRegions, 1, 'single');
Aest = zeros(imageSize, 'single');
M = false(imageSize);
nnr = 0;
blkSz = ceil(imageSize / min(10, floor(sqrt(queryLimit))));
for x = 1:blkSz:imageSize
    X = x:min(x+blkSz-1, imageSize);
    for y = 1:blkSz:imageSize
        Y = y:min(y+blkSz-1, imageSize);
        M(Y,X) = true;
        nnr = nnr + 1;
        regionSum(nnr) = queryImage(M);
        M(Y,X) = false;
        regionDims(:,nnr) = [Y([1 end])'; X([1 end])'];
        regionSize(nnr) = numel(Y) * numel(X);
        Aest(Y,X) = regionSum(nnr) / regionSize(nnr);
        regionIdx(Y,X) = nnr;
        queryLimit = queryLimit - 1;
    end
end
dy = abs(diff(Aest, 1, 1));
dy = [dy(1,:); max(dy(1:end-1,:), dy(2:end,:)); dy(end,:)];
dx = abs(diff(Aest, 1, 2));
dx = [dx(:,1) max(dx(:,1:end-1), dx(:,2:end)) dx(:,end)];
D = [accumarray(regionIdx(:), dx(:), [nnr 1], @max) accumarray(regionIdx(:), dy(:), [nnr 1], @max)];

d = 1;

while queryLimit
    D_ = D;
    D_(D_==300) = -1;
    D_ = D_ .* regionSize(1:nnr,[1 1]);
    
    % Choose the region
    while d >= 0
        [d n] = max(D_(:));
        vert = n > nnr;
        n = n - vert * nnr;
        dims = regionDims(:,n);
        if vert
            if dims(2) > dims(1)
                break;
            else
                D(n,2) = 300;
                D_(n,2) = -1;
            end
        else
            if dims(4) > dims(3)
                break;
            else
                D(n,1) = 300;
                D_(n,1) = -1;
            end
        end
    end
    if d < 0
        break;
    end
    
    if vert
        % Divide vertically
        % Top
        Y = dims(1):dims(1)+floor((dims(2)-dims(1))/2);
        X = dims(3):dims(4);
        % Bottom
        Y1 = Y(end)+1:dims(2);
        X1 = X;
    else
        % Divide horizontally
        % Left
        Y = dims(1):dims(2);
        X = dims(3):dims(3)+floor((dims(4)-dims(3))/2);
        % Right
        Y1 = Y;
        X1 = X(end)+1:dims(4);
    end
    
    % Compute new block
    M(Y,X) = true;
    nnr = nnr + 1;
    regionSum(nnr) = queryImage(M);
    M(Y,X) = false;
    regionDims(:,nnr) = [Y([1 end])'; X([1 end])'];
    regionSize(nnr) = numel(Y) * numel(X);
    regionIdx(Y,X) = nnr;
    
    % Update old block
    regionSize(n) = regionSize(n) - regionSize(nnr);
    regionSum(n) = regionSum(n) - regionSum(nnr);
    regionDims(:,n) = [Y1([1 end])'; X1([1 end])'];
    
    % Update the image
    Aest(Y,X) = regionSum(nnr) / regionSize(nnr);
    Aest(Y1,X1) = regionSum(n) / regionSize(n);
    
    % Compute regions' update scores
    Y = max(dims(1)-1, 1):min(dims(2)+1, imageSize);
    X = max(dims(3)-1, 1):min(dims(4)+1, imageSize);
    D_ = Aest(Y,X);
    dy = abs(diff(D_, 1, 1));
    dy = [dy(1,:); max(dy(1:end-1,:), dy(2:end,:)); dy(end,:)];
    dx = abs(diff(D_, 1, 2));
    dx = [dx(:,1) max(dx(:,1:end-1), dx(:,2:end)) dx(:,end)];
    D_ = regionIdx(Y,X);
    D_ = [accumarray(D_(:), dx(:), [nnr 1], @max) accumarray(D_(:), dy(:), [nnr 1], @max)];
    D([n nnr],:) = 0;
    D([n nnr],vert+1) = 300;
    D = max(D, D_);
    
    queryLimit = queryLimit - 1;
end

% Smooth using a gaussian filter
h = [0.25 0.5 0.25];
for a = 1:9
    Aest = conv2(h', h, Aest([1 1:end end],[1 1:end end]), 'valid');
    add = (regionSum(1:nnr) - accumarray(regionIdx(:), Aest(:), [nnr 1])) ./ regionSize(1:nnr);
    Aest = Aest + add(regionIdx);
    Aest = min(max(Aest, 0), 255);
end

% Apply bilateral filtering to improve edges
Aest = double(Aest);
regionSum = double(regionSum);
regionSize = double(regionSize);
for a = 1:1
    Aest = bilateralFilter(Aest, Aest, 0, 255, 3, 25.5);
    add = (regionSum(1:nnr) - accumarray(regionIdx(:), Aest(:), [nnr 1])) ./ regionSize(1:nnr);
    Aest = Aest + add(regionIdx);
    Aest = min(max(Aest, 0), 255);
end
Aest = round(Aest);
end

% Jiawen Chen's bilateral filtering code from:
% http://people.csail.mit.edu/jiawen/#code
function output = bilateralFilter( data, edge, edgeMin, edgeMax, sigmaSpatial, sigmaRange)

inputHeight = size( data, 1 );
inputWidth = size( data, 2 );

edgeDelta = edgeMax - edgeMin;
samplingSpatial = sigmaSpatial;
samplingRange = sigmaRange;

derivedSigmaSpatial = sigmaSpatial / samplingSpatial;
derivedSigmaRange = sigmaRange / samplingRange;

paddingXY = floor( 2 * derivedSigmaSpatial ) + 1;
paddingZ = floor( 2 * derivedSigmaRange ) + 1;

downsampledWidth = floor( ( inputWidth - 1 ) / samplingSpatial ) + 1 + 2 * paddingXY;
downsampledHeight = floor( ( inputHeight - 1 ) / samplingSpatial ) + 1 + 2 * paddingXY;
downsampledDepth = floor( edgeDelta / samplingRange ) + 1 + 2 * paddingZ;

[ jj, ii ] = meshgrid( 0 : inputWidth - 1, 0 : inputHeight - 1 );

di = round( ii / samplingSpatial ) + paddingXY + 1;
dj = round( jj / samplingSpatial ) + paddingXY + 1;
dz = round( ( edge - edgeMin ) / samplingRange ) + paddingZ + 1;

gridData = accumarray({di(:), dj(:), dz(:)}, data(:), [downsampledWidth downsampledHeight downsampledDepth]);
gridWeights = accumarray({di(:), dj(:), dz(:)}, 1, [downsampledWidth downsampledHeight downsampledDepth]);

kernelWidth = 2 * derivedSigmaSpatial + 1;
kernelHeight = kernelWidth;
kernelDepth = 2 * derivedSigmaRange + 1;

halfKernelWidth = floor( kernelWidth / 2 );
halfKernelHeight = floor( kernelHeight / 2 );
halfKernelDepth = floor( kernelDepth / 2 );

[gridX, gridY, gridZ] = meshgrid( 0 : kernelWidth - 1, 0 : kernelHeight - 1, 0 : kernelDepth - 1 );
gridX = gridX - halfKernelWidth;
gridY = gridY - halfKernelHeight;
gridZ = gridZ - halfKernelDepth;
gridRSquared = ( gridX .* gridX + gridY .* gridY ) / ( derivedSigmaSpatial * derivedSigmaSpatial ) + ( gridZ .* gridZ ) / ( derivedSigmaRange * derivedSigmaRange );
kernel = exp( -0.5 * gridRSquared );

blurredGridData = convn( gridData, kernel, 'same' );
blurredGridWeights = convn( gridWeights, kernel, 'same' );

blurredGridWeights( blurredGridWeights == 0 ) = -2; % avoid divide by 0, won't read there anyway
normalizedBlurredGrid = blurredGridData ./ blurredGridWeights;
normalizedBlurredGrid( blurredGridWeights < -1 ) = 0; % put 0s where it's undefined

[ jj, ii ] = meshgrid( 0 : inputWidth - 1, 0 : inputHeight - 1 ); % meshgrid does x, then y, so output arguments need to be reversed

di = ( ii / samplingSpatial ) + paddingXY + 1;
dj = ( jj / samplingSpatial ) + paddingXY + 1;
dz = ( edge - edgeMin ) / samplingRange + paddingZ + 1;

output = interpn( normalizedBlurredGrid, di, dj, dz );
end
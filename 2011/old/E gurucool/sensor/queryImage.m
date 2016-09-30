function pixelSum = queryImage(mask, imgInput, queryLimitInput)
    
    %   Copyright 2010 The MathWorks, Inc.

    persistent img queryCount queryLimit forbidden
    
    if nargin>1
        % This switch is for resetting the persistent variables at the
        % start of a run. Called only by the administrator. Do not try to
        % call queryImage with more than one input argument because the
        % internal image will be replaced.
        img = imgInput;
        queryLimit = queryLimitInput;
        forbidden = numel(img)+1;
        queryCount = 0;
        return
    end
    
    queryCount = queryCount + 1;
    if (queryCount > queryLimit) || (~islogical(mask))
        pixelSum = 0;
    else
        mask(forbidden:end) = false; % in case mask is larger than img
        pixelSum = sum(img(mask));
    end
    
end

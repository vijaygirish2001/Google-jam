function [message,results,timeElapsed,score] = runcontest(drawboard)
    % RUNCONTEST Test a Sensor contest entry.
    %
    %   [MESSAGE,RESULTS,TIME] = RUNCONTEST runs solver.m against all
    %   problems defined in testsuite_sample.mat. MESSAGE returns a summary
    %   of the testing.  RESULTS measures how well the entry solved the problem
    %   and TIME measures the time the entry took to compute its answer.
    %
    %   ... = RUNCONTEST(TRUE) shows each of the solutions.

    %   Copyright 2010 The MathWorks, Inc.

    % Set run mode.
    if (nargin == 0)
        drawboard = 0;
    end
    
    testFilename = 'testsuite_sample';
    
    % Load the testsuite
    load(testFilename)
    
    % Run the submission for each problem in the suite.
    numTests = numel(testsuite);
    responses = cell(numTests,1);
    score = zeros(numTests,1);
    
    time0 = cputime;
    
    for k = 1:numTests
        % Clear the function and persistent variables.
        clear queryImage
        
        % Set up the persistent variables with the next puzzle.
        img = testsuite(k).image;
        queryLimit = testsuite(k).queryLimit;
        queryImage(0,img,queryLimit)
        
        % Solve the puzzle.
        responses{k} = solver(size(img,1),queryLimit);
        
        if drawboard
            subplot(1,2,1)
            imagesc(responses{k})
            colormap(gray)
            axis square
            title('Estimated')
            subplot(1,2,2)
            imagesc(img)
            colormap(gray)
            axis square
            title('Actual')
            pause(1)
        end
        
    end
    timeElapsed = cputime-time0;
    
    % Grade all answers.
    for k = 1:numTests
        score(k) = grade(responses{k}, testsuite(k).image);
    end
    
    % Report results.
    results = sum(score);
    message = sprintf('results: %.0f\ntime: %.4f',results,timeElapsed);
    
end

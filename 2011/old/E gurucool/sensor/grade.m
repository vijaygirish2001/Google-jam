function score = grade(solution, test)
    %GRADE Make sure the answer is valid and compute its score.
    
    %   Copyright 2010 The MathWorks, Inc.
    
    imageDiff = abs(solution - test);
    score = sum(imageDiff(:));
    
end
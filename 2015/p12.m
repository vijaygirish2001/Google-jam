clc  
clear all
%

% Read the input file 

film=fopen('B-large-practice.in');
    fileid = fopen('out.txt','w');

t=fscanf(film,'%d',1);
for k=1:t
    
    n=fscanf(film,'%d',1);
    m=fscanf(film,'%d\n',1);

    dim=fscanf(film,'%d\n',n);
   fprintf(fileid,'Case #%d: \n',k); 

    for k1=1:m
        
       lr= fscanf(film,'%d\n',2);
        
       cln=1;
       % Lengths area
       for k2=lr(1):lr(2)
       cln=cln*dim(k2+1)^(1/(lr(2)-lr(1)+1));
       
       end
         fprintf(fileid,'%f \n',cln); 
 
    end
end


fclose(film);
% Output file

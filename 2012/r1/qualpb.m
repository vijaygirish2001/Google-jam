clc
clear all

inp=fopen('B-large.in','r');

out=fopen('outblarge','w');

t=fscanf(inp,'%d',1);

for k=1:t
    a=fscanf(inp,'%d',1);
    b=fscanf(inp,'%d',1);
    
    
    y=0;
    nosurp=0;
    p=zeros(1,a);
    for i=1:a
        
        
            p(i)=fscanf(inp,'%f',1);

        
    end
    
    
    fprintf(out,'Case #%d: %d\n',k,y);
end

fclose('all')

clc
clear all

inp=fopen('B-large.in','r');

out=fopen('outblarge','w');

t=fscanf(inp,'%d',1);

for k=1:t
    n=fscanf(inp,'%d',1);
    s=fscanf(inp,'%d',1);
    p=fscanf(inp,'%d',1);
    
    x=fscanf(inp,'%d',n);
    
    y=0;
    nosurp=0;
    for i=1:n
        
        
        if p==0
            y=y+1;
            continue
        end
        if x(i)==0 && p>0
            continue
        end
        if x(i)>=3*p-2
            y=y+1;
        elseif x(i)>=3*p-4 && nosurp<s
            y=y+1;
            nosurp=nosurp+1;
        else
        end
        
        
    end
    
    
    fprintf(out,'Case #%d: %d\n',k,y);
end

fclose('all')

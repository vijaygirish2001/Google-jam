clc
clear all

inp=fopen('inp1.txt','r');

out=fopen('oup1','w');

t=fscanf(inp,'%d',1);

for k=1:t
    a=fscanf(inp,'%d',1);
    b=fscanf(inp,'%d',1);
    
    
    y=0;
    nosurp=0;
    p=zeros(1,a);
        ky=zeros(1,a);

    for i=1:a
        
        
            p(i)=fscanf(inp,'%f',1);

        
    end
     pj=zeros(1,2^a);
    
    cm=zeros(1,a);
    ind=a;
    for i=1:2^a
        
        if i==2^(a-ind)
        cm(ind)=1-cm(ind);
        
        end
        
        for h=1:2
           if h==1 
%            pj(i)=pj(i)*p(h); 
           else
%            pj(i)=pj(i)*(1-p(h)); 
           end   
        end
        
    end
    
    
    
    
    
    fprintf(out,'Case #%d: %d\n',k,y);
end

fclose('all')
a=4;
    cm=zeros(1,a);
ind=a
 for i=1:2^a
        i
        if i==2^(a-ind) && ind>0
        cm(ind)=1-cm(ind);
        ind=ind-1;
        end
        
        cm
 end
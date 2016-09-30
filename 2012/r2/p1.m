clc
clear all

inp=fopen('A-small-attempt1.in','r');

out=fopen('oup1.txt','w');

t=fscanf(inp,'%d',1);

for k=1:t
    n=fscanf(inp,'%d',1);
    
    s=zeros(1,n);
    

    for i=1:n
        
        
            s(i)=fscanf(inp,'%d',1);

        
    end
        
    x=sum(s);
            y=zeros(1,n);

            
            a=zeros(n);
   i=1;ind=1;
       for k2=i+1:n
           a(ind,i)=1;
           a(ind,k2)=-1;
           y(ind)=(s(k2)-s(i))/x;
           ind=ind+1;
       end
        a(ind,:)=1;
        y(ind)=1;
       ymin=inv(a)*y'*100;
    
       
       for i=1:n
           if ymin(i)<0
           ymin(i)=0;
           end
       end
%         ymin(i)=min(y)*100;
        
        
    
    
    
    
    
    fprintf(out,'Case #%d: ',k);
    
        for i=1:n

            fprintf(out,'%f ',ymin(i));
        end
            fprintf(out,'\n');

end

fclose('all')

clc
clear all

inp=fopen('C-large.in','r');

out=fopen('outclarge','w');

t=fscanf(inp,'%d',1);

for k=1:t
    a=fscanf(inp,'%d',1);
    b=fscanf(inp,'%d',1);
    nos=0;
    nref=zeros(b-a,1);
    k2=0;
    for n=a:b
       ns=num2str(n);
       f=10;
       k2=k2+1;
       nref(k2)=n;
       if length(ns)>1
           while(round(n/f)>0)
               sup=rem(n,f);
               sub=round((n-sup)/f);
               nn=str2num([num2str(sup) num2str(sub)]);
               f=f*10;
               if nn>=a && nn<=b && nn~=n && sup>0 && isempty(find(nref==nn,1))
                   [n sup sub nn];
                  nos=nos+1;
               end
           end
           
       end
        
    end
    
    
    fprintf(out,'Case #%d: %d',k,nos);
        fprintf(out,'\n');

end

fclose('all')

clc
clear all

in=fopen('A-small-attempt0.in','r');
out=fopen('outaqual','w');


inp=fopen('inpa.txt','r');

out1=fopen('outa.txt','r');

k=0;
while ~feof(inp)
    curr = fscanf(inp,'%c',1);
    curr1 = fscanf(out1,'%c',1);
    if ~isempty(curr)
        if curr<=122 && curr>=97
            k = k+1;
            
            inref(k) = curr;
            outref(k) = curr1;
            ref(double(curr)-96)=curr1;
            
        end
    end
end
refs=sort(ref);
k1=97;
for k=1:length(ref)
    if refs(k)~=k1
        ref( length(ref)+1)=char(k1);
        break;
    end
    k1=k1+1;
end

t=fscanf(in,'%d',1);
curr='';
l=1;
while ~feof(in)
    curr = fscanf(in,'%c',1);
%     while(~strcmp(curr,'\n'));
         if  curr==10
                         fprintf(out,'\n')

            fprintf(out,'Case #%d: ',l)
            l=l+1;
            continue
         end
    if ~isempty(curr)
         
        if curr<=122 && curr>=97
            fprintf(out,'%c',ref(curr-96));
        else
                        fprintf(out,'%c',curr);

        end
    end
        

%     end
end



fclose('all')

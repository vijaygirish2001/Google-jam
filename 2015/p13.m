clc  
clear all
%

% Read the input file 

film=fopen('C-small-practice.in');
    fileid = fopen('out.txt','w');

t=fscanf(film,'%d',1);
for k=1:t
    
    n=fscanf(film,'%d',1);
    m=fscanf(film,'%d\n',1);

   fprintf(fileid,'Case #%d: \n',k); 
% cost matrix
cm=zeros(n);
mcm=cm;
cmind=cm;
   uvc=zeros(m,3);
    for k1=1:m
        
       uvc(k1,:)= fscanf(film,'%d\n',3);
        uvc(k1,1:2)=uvc(k1,1:2)+1;
       if cm(uvc(k1,1),uvc(k1,2))==0
           cm(uvc(k1,1),uvc(k1,2))=uvc(k1,3);
           cm(uvc(k1,2),uvc(k1,1))=cm(uvc(k1,1),uvc(k1,2));
           cmind(uvc(k1,2),uvc(k1,1))=k1;
           cmind(uvc(k1,1),uvc(k1,2))=k1;

       else
           pause
       end
       
       
    end
    
    % Sort
    [cst,indsrt]=sort(uvc(:,3),'descend');
    
        [indsr,indsrt1]=sort(uvc(:,1),'ascend');
      g=uvc(indsrt1,:);
    for k2=1:length(indsrt)
        prcst=cst(k2);
        ind=indsrt(1);
        % Find the connection and see if cost exceeds
        cstin=prcst;
        
        [a,b]=find(uvc(:,1:2)==uvc(ind,1));
        
        
        
        
    end
    
    % print inefficient roads
 %     fprintf(fileid,'%f \n',cln); 
 
end


fclose(film);
% Output file

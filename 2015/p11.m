clc  
clear all
%

% Read the input file 

film=fopen('A-small-practice.in');

h=fscanf(film,'%d');

fclose(film);
% Output file
fileid = fopen('out.txt','w');

tmx=100;
kmx=10^14;

t=h(1);
k=h(2:end);


str=0;
while length(str)<max(k)
   
   % Invert string
   ln=length(str);
   strinv=ones(1,ln)-str;
   
   % Reverse and Append
 
   str=[ str 0 strinv(end:-1:1)];
   
   
end
x=str(k);
%}

%% large data 

film=fopen('A-large-practice.in');

h=fscanf(film,'%ld');

fclose(film);
t=h(1);
k=h(2:end);

%k=1:16;
% Top down approach

for m=1:length(k)
    ki=0;
    % initialize pres loc index
    ind=1;
    % present k
   ki(ind)=k(m);
   
  
   % Present iteration 
   pind=ceil(log2(ki(ind)+1));
   % length of the presest
           ln=2^pind-1;

  while ki(ind)>1
   
      ind=ind+1;

        ki(ind)=ln-ki(ind-1)+1;

   % See  if the pres ind is the mid point
        if ki(ind)==ki(ind-1)

            break
        end
     % Present iteration 
   pind=ceil(log2(ki(ind)+1));
   % length of the presest
           ln=2^pind-1;
  end
 
  if length(ki)>1
     if ki(end)==ki(end-1) %If a mid point 
         % No of switches
         n=length(ki)-2;
         
     else
         n=length(ki)-1;
         
         
     end
     n;
     y(m)=rem(n,2);
  else
      y(m)=0;
  end
      % y(m)=kioutfin;
   fprintf(fileid,'Case #%d: %d\n',m,y(m)); 
   df{m}=ki;
end

fclose(fileid)
y
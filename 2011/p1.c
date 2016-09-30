#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
/* practice */
int main()
{
FILE *ip,*op;
op = fopen("res", "w");
ip = fopen("A-large.in", "r");
int d,t,n,k,i,j,ind,r,c;
char m[52][52],p[51][51];

fscanf(ip,"%d ",&t);
for(k=1;k<=t;k++) 
{
fscanf(ip,"%d ",&r);
fscanf(ip,"%d ",&c);

for(i=1;i<=r;i++)
{
for(j=1;j<=c;j++)
fscanf(ip,"%c",&m[i][j]);

fscanf(ip,"\n");
}

for(i=1;i<=r;i++)
m[i][c+1]='.';

for(i=1;i<=c;i++)
m[r+1][i]='.';

i=1;
ind=0;
while(i<=r)
{
j=1;
while(j<=c)
{
if(m[i][j]=='.' || m[i][j]=='/' || m[i][j]=='\\')
{

j++;
continue;
}
else
{


if(i==1)
{
if(m[i][j]=='#' && m[i][j+1]=='#' && m[i+1][j]=='#' && m[i+1][j+1]=='#')
{
m[i][j]='/';
m[i][j+1]='\\';
m[i+1][j]='\\';
m[i+1][j+1]='/';


j=j+2;
}
else
{ind=1;break;
}
}
else
{



if(m[i][j]=='#' && m[i][j+1]=='#' && m[i+1][j]=='#' && m[i+1][j+1]=='#')
{
m[i][j]='/';
m[i][j+1]='\\';
m[i+1][j]='\\';
m[i+1][j+1]='/';


j=j+2;
}
else
{ind=1;break;

}
}
}
}




if(ind==1)
break;

i++;
}

if(ind==1)
{fprintf(op,"Case #%d:\nImpossible\n",k);
printf("Case #%d:\nImpossible\n",k);
}
else
{

fprintf(op,"Case #%d:\n",k);
printf("Case #%d:\n",k);
for(i=1;i<=r;i++)
{
for(j=1;j<=c;j++)
{
fprintf(op,"%c",m[i][j]);
printf("%c",m[i][j]);
}
fprintf(op,"\n");
printf("\n");
}



}

}
}







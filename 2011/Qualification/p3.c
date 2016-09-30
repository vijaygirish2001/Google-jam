#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* practice */
int main()
{
FILE *ip,*op;
op = fopen("C-small-practiceout", "w");
ip = fopen("C-large.in", "r");
int c[1002],d,t,n,k,j,i,r,ind,bi[1002][30],nod[1002],no1[30],maxi,minno,sumno;

fscanf(ip,"%d ",&t);
for(k=1;k<=t;k++) 
{
fscanf(ip,"%d ",&n);

for(j=0;j<30;j++)
no1[j]=0;
sumno=0;
maxi=0;

for(j=0;j<n;j++)
{
fscanf(ip,"%d ",&c[j]);
if(j==0)
minno=c[j];
else
{
if(c[j]<minno)
minno=c[j];
}

sumno=sumno+c[j];

r=c[j];
i=0;
ind=0;

while(r>0)
{
bi[j][i]=r%2;
r=(int)(r/2);


if(bi[j][i]==1)
no1[i]=no1[i]+1;

i=i+1;
}
nod[j]=i;
if(i>maxi)
maxi=i;


} 

for(j=0;j<maxi;j++)
if(no1[j]%2>0)
{
ind=1;
break;
}

if(ind==1)
fprintf(op,"Case #%d: NO\n",k);
else
{
sumno=sumno-minno;
fprintf(op,"Case #%d: %d\n",k,sumno);
}


}



}

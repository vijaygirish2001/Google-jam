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
ip = fopen("inp", "r");
int d,t,k,i,j,ind,a,n,m,u[2001],v[2001],c,un[2001],unv,vnv,nov[2001];


fscanf(ip,"%d ",&t);
for(k=1;k<=t;k++) 
{
fscanf(ip,"%d ",&n);
fscanf(ip,"%d\n",&m);
for(i=1;i<=m;i++)
fscanf(ip,"%d ",&u[i]);

for(i=1;i<=m;i++)
fscanf(ip,"%d ",&v[i]);

c=n;
ind=0;
for(i=1;i<=m;i++)
{
if(abs(v[i]-u[i])>n/2)
d=n-abs(v[i]-u[i])+1;
else
d=abs(v[i]-u[i])+1;

nov[i]=d;
if(c>d)
c=d;
unv=0;vnv=0;
for(j=1;j<=ind;j++)
{
if(u[i]==un[j])
unv=1;

if(v[i]==un[j])
vnv=1;

}

if(unv==0)
{

ind=ind+1;
un[ind]=u[i];
}

if(vnv==0)
{

ind=ind+1;
un[ind]=v[i];
}


}


if(c>ind && ind>2)
c=ind;

fprintf(op,"Case #%d: %d\n",k,c);



for(i=1;i<=m;j++)
{


}

}



}







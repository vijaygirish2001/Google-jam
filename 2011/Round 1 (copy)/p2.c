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
int d,t,k,i,j,ind,a,n,m,u[2001],v[2001],c;


fscanf(ip,"%d ",&t);
for(k=1;k<=t;k++) 
{
fscanf(ip,"%d ",&n);
fscanf(ip,"%d\n",&m);
for(i=1;i<=m;i++)
fscanf(ip,"%d ",&u[i]);

for(i=1;i<=m;i++)
fscanf(ip,"%d ",&v[i]);

c=0;
for(i=1;i<=m;i++)
{
if(abs(v[i]-u[i])>n/2)
printf("%d\n",abs(v[i]-u[i]));

}


fprintf(op,"Case #%d\n",k);

}



}







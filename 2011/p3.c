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
ip = fopen("C-large.in", "r");
int d,t,n,l,h,k,i,j,ind,r,c,no[10001];
char m[52][52],p[51][51];

fscanf(ip,"%d ",&t);
for(k=1;k<=t;k++) 
{
fscanf(ip,"%d ",&n);
fscanf(ip,"%d ",&l);
fscanf(ip,"%d",&h);
for(i=1;i<=n;i++)
fscanf(ip,"%d ",&no[i]);


for(i=l;i<=h;i++)
{
ind=0;
for(j=1;j<=n;j++)
{if(no[j]%i==0 || i%no[j]==0)
ind=ind+1;
}
if(ind==n)
{
d=i;
break;

}


}

if(ind==n)
{
fprintf(op,"Case #%d: %d\n",k,d);
printf("Case #%d: %d\n",k,d);
}
else
{
fprintf(op,"Case #%d: NO\n",k);
printf("Case #%d: NO\n",k);
}






}
}







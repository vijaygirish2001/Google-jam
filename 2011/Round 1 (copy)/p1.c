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
int d,t,n,k,i,j,ind,a[101][101],b[101][101];
double owp[101],wp[101],oowp[101],rip[101],sa,sb,la,lb,y,p;
char c;
fscanf(ip,"%d ",&t);
for(k=1;k<=t;k++) 
{
fscanf(ip,"%d ",&n);

for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{fscanf(ip,"%c ",&c);
if(c=='1')
{
a[i][j]=1;
b[i][j]=1;

}
if(c=='0')
{
a[i][j]=0;
b[i][j]=1;

}

if(c=='.')
{
a[i][j]=0;
b[i][j]=0;

}



}

for(i=1;i<=n;i++)
{
sa=0;sb=0;
for(j=1;j<=n;j++)
{sa=sa+a[i][j];
sb=sb+b[i][j];
}

wp[i]=sa/sb;

y=0;
for(j=1;j<=n;j++)
{
la=-a[j][i];lb=-b[j][i];
for(d=1;d<=n;d++)
{la=la+a[j][d];
lb=lb+b[j][d];


}

y=y+la/lb*b[i][j];
}

owp[i]=y/sb;




}

fprintf(op,"Case #%d:\n",k);

for(i=1;i<=n;i++)
{

sb=0;
for(j=1;j<=n;j++)
{
sb=sb+b[i][j];
}

p=0;
for(j=1;j<=n;j++)
p=p+owp[j]*b[i][j];

oowp[i]=p/sb;

rip[i]=0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i];
fprintf(op,"%f\n",rip[i]);

}



}




}





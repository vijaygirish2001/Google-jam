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
ip = fopen("A-small-practice.in", "r");
int d,t,n,k,j,ind,no1[30],maxi,minno,sumno,pd,pg,x;
double i,r;
fscanf(ip,"%d ",&t);
for(k=1;k<=t;k++) 
{
fscanf(ip,"%d ",&n);

fscanf(ip,"%d ",&pd);

fscanf(ip,"%d ",&pg);
j=0;
for(i=1;i<=n;i++)
{
r=pd*i/10;

if((int)r%10==0)
{j=i;break;
}
}



if(j==0 || (pg==100 && pd<100) || (pg==0 && pd>0))
fprintf(op,"Case #%d: Broken\n",k);
else
{
for(d=pg;d>=1;d--)
{if(pg%d==0 && 100%d==0)
{x=d;break;
}
}

if((j*(pg-pd))%x==0)
{fprintf(op,"Case #%d: Possible\n",k);

}
else
{
ind=0;
for(i=j;i<=n;i++)
{
r=pd*i/10;
ind=0;





if((int)r%10==0 && (int)(i*(pg-pd))%x==0)
{j=i;fprintf(op,"Case #%d: Possible\n",k);ind=1; break;
}
}
if(ind==0)
fprintf(op,"Case #%d: Broken\n",k);


}

}


}


}





#include<stdio.h>
#include <stdlib.h>
#include <time.h>


/* practice */
int main()
{
FILE *ip,*op;
op = fopen("A-small-practiceout", "w");
ip = fopen("A-large-practice.in", "r");
int n,c,i,p[2010],j,k,m,b;
fscanf(ip,"%d",&n);
for(k=1;k<=n;k++) 
{
fscanf(ip,"%d",&c);
fscanf(ip,"%d",&i);

for(j=0;j<i;j++)  
fscanf(ip,"%d",&p[j]);


printf("\n");
printf("%d\n",c);
printf("%d\n",i);


for(j=0;j<i;j++) 
{for(m=j;m<i;m++)
{if(p[j]+p[m]==c)
{fprintf(op,"Case #%d: %d %d \n",k,j+1,m+1);
printf("\nk=%d\n",k);
break;
}
}
if(p[j]+p[m]==c)
break;

}

}


}

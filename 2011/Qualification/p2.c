#include<stdio.h>
#include <stdlib.h>
#include <time.h>


/* practice */
int main()
{
FILE *ip,*op;
op = fopen("B-small-practiceout", "w");
ip = fopen("B-large.in", "r");
int c,d,t,n,k,j,i,r,ind;
char cmb[40][3],opp[30][2],inp[110],list[110],nolist;
char ch;
fscanf(ip,"%d ",&t);
for(k=1;k<=t;k++) 
{
fscanf(ip,"%d ",&c);

for(j=0;j<c;j++)  
fscanf(ip,"%c%c%c ",&cmb[j][0],&cmb[j][1],&cmb[j][2]);



fscanf(ip,"%d ",&d);

for(j=0;j<d;j++)  
fscanf(ip,"%c%c ",&opp[j][0],&opp[j][1]);

fscanf(ip,"%d ",&n);

nolist=0;
for(j=0;j<n;j++)  
{fscanf(ip,"%c",&inp[j]);




ind=0;
if(j>0 && nolist>0)
{
for(i=0;i<c;i++)
{

if((cmb[i][0]==inp[j] && cmb[i][1]==list[nolist-1])||(cmb[i][1]==inp[j] && cmb[i][0]==list[nolist-1]))
{list[nolist-1]=cmb[i][2];

nolist=nolist; ind=1;
break;
}
}
if(ind==0)
for(i=0;i<d;i++)
{
if(inp[j]==opp[i][0])
{
for(r=0;r<nolist;r++)
{
if(list[r]==opp[i][1])
{nolist=0;ind=1;break;}
}
}
if(inp[j]==opp[i][1])
{
for(r=0;r<nolist;r++)
{
if(list[r]==opp[i][0])
{nolist=0;ind=1;break;}
}
}
}
if(ind==0)
{
list[nolist]=inp[j];
nolist=nolist+1;
}
}
else
{
list[0]=inp[j];
nolist=nolist+1;
}
}
fprintf(op,"Case #%d: [",k);
for(r=0;r<nolist-1;r++)
fprintf(op,"%c, ",list[r]);
fprintf(op,"%c]\n",list[nolist-1]);

printf("Case #%d: [",k);
for(r=0;r<nolist-1;r++)
printf("%c, ",list[r]);
printf("%c]\n",list[nolist-1]);
}



}

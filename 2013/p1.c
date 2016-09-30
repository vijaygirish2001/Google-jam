#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* practice */
int main()
{
FILE *ip,*op;
op = fopen("op", "w");
ip = fopen("in", "r");
int t,k,j,n,ch[4][4],g=1,vert,hor,diag,diag1;
char a;
fscanf(ip,"%d",&t);
for(n=1;n<=t;n++) {
                  g=1;
for(k=0;k<=3;k++) 
{
for(j=0;j<=3;j++)  
{
fscanf(ip,"%c ",&a);

if (a=='X')
ch[k][j]=1;

if (a=='T')
ch[k][j]=0;

if (a=='O')
ch[k][j]=-1;

if (a=='.'){
g=0;
ch[k][j]=-10;

}

printf("%d \n",ch[k][j]);
}


}

diag=0;
diag1=0;
for(k=0;k<=3;k++) 
{
                  
vert=0;
hor=0;


for(j=0;j<=3;j++)  
{
vert=vert+ch[j][k];
hor=hor+ch[k][j];

}
diag=diag+ch[k][k];
diag1=diag+ch[k][3-k];
if(vert>=3 || hor>=3){
fprintf(op,"Case #%d: X won\n",n);g=2;break;}
if(vert==-3 || hor==-3 || vert==-4 || hor==-4){
fprintf(op,"Case #%d: O won\n",n);g=2;break;}
printf("%d %d %d\n",n,hor,vert);
}
if(g==2)
continue;
if(diag>=3 || diag1>=3){
fprintf(op,"Case #%d: X won\n",n);g=2;}
if(diag==-3 || diag1==-3 || diag==-4 || diag1==-4){
fprintf(op,"Case #%d: O won\n",n);g=2;}

if(g==0)
fprintf(op,"Case #%d: Game has not completed\n",n);
else if(g==1)
fprintf(op,"Case #%d: Draw\n",n);

}
}

#include<stdio.h>
#include <stdlib.h>
#include <time.h>


/* practice */
int main()
{
FILE *ip,*op;
op = fopen("A-large-practiceout", "w");
ip = fopen("A-large.in", "r");
int n,i,t,j,k,o[101],b[101],pos[101],nino,ninb,nosec,bpos,opos,ino,inb;
char ch;
fscanf(ip,"%d",&t);
for(k=1;k<=t;k++) 
{
fscanf(ip,"%d ",&n);
nino=0;
ninb=0;
for(j=0;j<n;j++)  
{
fscanf(ip,"%c ",&ch);

fscanf(ip,"%d ",&i);
if(ch=='B')
{b[ninb]=i;
ninb=ninb+1;
pos[j]=1;
}
else
{
o[nino]=i;
nino=nino+1;
pos[j]=2;
}
/*printf("%c\n",ch);*/
}

nosec=0;
bpos=1;
opos=1;
ino=0;
inb=0;
for(j=0;j<n;j++)  
{
if(pos[j]==1)
{
if(b[inb]-bpos>=0)
{nosec=nosec+b[inb]-bpos+1;
if(o[ino]-opos>0 && b[inb]-bpos+1>=o[ino]-opos)
opos=o[ino];
if(o[ino]-opos>0 && b[inb]-bpos+1<o[ino]-opos)
opos=opos+b[inb]-bpos+1;
if(o[ino]-opos<0 && b[inb]-bpos+1>=opos-o[ino])
opos=o[ino];
if(o[ino]-opos<0 && b[inb]-bpos+1<opos-o[ino])
opos=opos-(b[inb]-bpos+1);

bpos=b[inb];
inb=inb+1;
}
else
{nosec=nosec+1-(b[inb]-bpos);
if(o[ino]-opos>0 && bpos-b[inb]+1>=o[ino]-opos)
opos=o[ino];
if(o[ino]-opos>0 && bpos-b[inb]+1<o[ino]-opos)
opos=opos+bpos-b[inb]+1;
if(o[ino]-opos<0 && bpos-b[inb]+1>=opos-o[ino])
opos=o[ino];
if(o[ino]-opos<0 && bpos-b[inb]+1<opos-o[ino])
opos=opos-(bpos-b[inb]+1);

bpos=b[inb];
inb=inb+1;
}
}


else
{
if(o[ino]-opos>=0)
{nosec=nosec+o[ino]-opos+1;
if(b[inb]-bpos>0 && o[ino]-opos+1>=b[inb]-bpos)
bpos=b[inb];
if(b[inb]-bpos>0 && o[ino]-opos+1<b[inb]-bpos)
bpos=bpos+o[ino]-opos+1;
if(b[inb]-bpos<0 && o[ino]-opos+1>=bpos-b[inb])
bpos=b[inb];
if(b[inb]-bpos<0 && o[ino]-opos+1<bpos-b[inb])
bpos=bpos-(o[ino]-opos+1);

opos=o[ino];
ino=ino+1;
}
else
{nosec=nosec+1-(o[ino]-opos);
if(b[inb]-bpos>0 && opos-o[ino]+1>=b[inb]-bpos)
bpos=b[inb];
if(b[inb]-bpos>0 && opos-o[ino]+1<b[inb]-bpos)
bpos=bpos+opos-o[ino]+1;
if(b[inb]-bpos<0 && opos-o[ino]+1>=bpos-b[inb])
bpos=b[inb];
if(b[inb]-bpos<0 && opos-o[ino]+1<bpos-b[inb])
bpos=bpos-(opos-o[ino]+1);

opos=o[ino];
ino=ino+1;
}
}

}



fprintf(op,"Case #%d: %d \n",k,nosec);



}


}

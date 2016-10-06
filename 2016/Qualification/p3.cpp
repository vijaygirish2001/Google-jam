#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    int cases=0,n,j;
    ofstream op_file;
    op_file.open("output_file");
    char a;
    //string s;
    int input_count=0, rem;
    //read the input file
    ifstream file_h;
    string sl;
    file_h.open("C-small-practice.in");
    file_h>>cases;
    //file_h>>cases;
    //std::getline(file_h,sl);
    //cout<<input[0];
    //cout<<sl;
//int fac[10];
cout<<cases<<endl;
cout<<cases<<endl;

for(int i=1; i<=cases; i++)
    {
file_h>>n;
file_h>>j;

char bin[n];
op_file<<"Case #"<<i<<':'<<endl;
int exp=1;
int k=1;
while(k<=j)
{
//
int exptemp=0;
exptemp=exp;
do{


for(int k2=1;k2<=n;k2++){bin[k2-1]='0';}

bin[0]='1';
bin[n-1]='1';

for( int k3=exptemp; k3<=exp;k3++){
bin[k3]='1';
bin[n-k3-1]='1';

}
bin[n]='\0';
cout<<bin<<' '<<endl;

op_file<<bin<<' ';
for(int k4=2;k4<=10;k4++){
long long int fac=1;
int expt=exptemp;
while(expt<=exp)
{fac=fac+pow(k4,expt);
expt++;
}
op_file<<fac<<' ';

}
op_file<<endl;
exptemp=exptemp-1;

k++;

}
while(exptemp>=1  & k<=j);

exp++;
}

}




    file_h.close();


    op_file.close();
   return 0;
    //for(int i=0; i<;i++){
    //cout << input[i]<< endl;
    //}
}

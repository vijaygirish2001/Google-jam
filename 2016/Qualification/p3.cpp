#include <iostream>
#include <fstream>

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

cout<<cases;
for(int i=1; i<=cases; i++)
    {
file_h>>n;
file_h>>j;
cout<<n<<j;
op_file<<"Case #"<<i<<endl;
for(int k=1;k<=9;k++)
{



}

    }


    file_h.close();


    op_file.close();
    return 0;
    //for(int i=0; i<;i++){
    //cout << input[i]<< endl;
    //}
}

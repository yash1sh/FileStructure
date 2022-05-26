
//Printing TExting in different file prg1








#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream f1;
    char ch;
    char input[20];
    cout<<"Enter the file name\n";
    cin>>input;
    f1.open(input,ios::in);
    f1.unsetf(ios::skipws);
    while(1)
    {
        f1>>ch;
        if(f1.fail()) break;
        cout<<ch;
    }
    return 0;




}
//Printing reverse names from one file  to another
#include<fstream>
#include<string.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class prg3
{
    private:char a[10][10];
    public: void std_io();
            void file_io();

};

void prg3::std_io()
{
    fstream f1,f2;
    string s1;
    cout<<"enter the file name\n";
    cin>>s1;
    f1.open(s1,ios::in);
    cout<<"Enter the new file name";
    cin>>s1;
    f2.open(s1,ios::out);
    while(1)
    {
        getline(f1,s1);
        if(f1.fail()) break;  
        
        reverse(s1.begin(),s1.end());
        f2<<s1<<"\n";
    }
}

int main()
{
    prg3 x;
    x.std_io();
}

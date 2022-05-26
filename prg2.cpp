//Printing reverse names
#include<string.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class prg2
{
    private:char a[10][10];
    public: void std_io();

};

void prg2::std_io()
{
    int n,i;
    string s1;
    cout<<"enter thghe no of name\n";
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    {
        s1=a[i];
        reverse(s1.begin(),s1.end());
        cout<<s1<<"\n";
    }
}

int main()
{
    prg2 x;
    x.std_io();
}

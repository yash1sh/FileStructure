#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;
class student
{
    private:char buf[40],name[10],sem[10],branch[10],extra[40]; 
    public: void read()
    {
        cout<<"Name: ";
        cin>>name;
        cout<<"Semester: "<<endl;
        cin>>sem;
        cout<<"Branch: "<<endl;
        cin>>branch;
    }
    void insert(fstream &ofile,char rrn[])
    {

        read();
        strcpy(buf," ");
        strcat(buf,rrn);
        strcat(buf,"|");
        strcat(buf,name);
        strcat(buf,"|");
        strcat(buf,sem);
        strcat(buf,"|");
        strcat(buf,branch);
        strcat(buf,"|");
        strcat(buf,"\n");
        ofile.write(buf,strlen(buf));
    }
    int search(fstream &ifile,char key[])
    {
        char rrn[10];
        while(!ifile.eof())
        {
            ifile.getline(rrn,10,'|');
            ifile.getline(name,10,'|');
            ifile.getline(sem,10,'|');
            ifile.getline(branch,10,'|');
            ifile.getline(extra,40,'\n');
            if(strcmp(key,rrn) == 0)
            {
                cout<<"Record found and details are:\n"<<endl;
                cout<<"Name: "<<name<<"\n";
                cout<<"Semester: "<<sem<<"\n";
                cout<<"Branch: "<<branch<<"\n";
                return 1;
            }
        }
        return 0;
    }

};
int main()
{
    int n,i,ch,k=0;
    char key[10];
    student stu;
    fstream ofile,ifile;
    ofile.open("student2.txt",ios::trunc|ios::app);
    ofile.close();
    for(;;)
    {
        cout<<"1.Insert\n2.Search\n3.Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch (ch)
        {
            case 1:
                ofile.open("student2.txt",ios::out|ios::app);
                cout<<"Enter the no. of students: ";
                cin>>n;
                for(i=0;i<n;i++)
                {
                    k=sprintf(key,"%d",++k);
                    stu.insert(ofile,key);
                }
                ofile.close();
                break;
            case 2: cout<<"Enter the RRN to search: ";
                cin>>key;
                ifile.open("student2.txt",ios::in);
                if(stu.search(ifile,key)==0)
                    cout<<"Record not found\n";
                break;
            default:exit(0);
        }
    }
}
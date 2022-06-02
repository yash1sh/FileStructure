#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string.h>
using namespace std;
class student{
    private: char name[20];
            char sem[5]; 
            char branch[4];
             char buff[45];
    public: void read()
            {
                cout<<"Enter name\n";
                cin>>name;
                cout<<"enter the sem\n";
                cin>>sem;
                cout<<"Enter the branch\n";
                cin>>branch;
            }
            void pack(fstream &ofile)
            {
                //read();
                //strcpy(buff," ");
                strcat(buff,name);
                strcat(buff,"|");
                strcat(buff,sem);
                strcat(buff,"|");
                strcat(buff,branch);
                strcat(buff,"|");
                while (strlen(buff)<45)
                {
                    strcat(buff," ");
                }
                strcat(buff,"\n");
                ofile.write(buff,strlen(buff));
                
            }
            void file_io(int chr)
            {
              
                char filename[10];
                fstream ofile;
               if(chr==1)
                {
                    // file_read(ofile);
                    file_readAs(ofile);
                }
               else{ 
                cout<<"Enter the file name";
                cin>>filename;
                 
                ofile.open(filename,ios::out|ios::app);
                pack(ofile);
               }
            }
            void file_read(fstream &ofile)
            {
                char ch;
                char filename[10];
                cout<<"Enter the file name";
                cin>>filename;
                ofile.open(filename,ios::in);
                while (1)
                {
                ofile>>ch;
                if(ofile.fail()) break;
                ofile.unsetf(ios::skipws);
                
                cout<<ch;
                }
                
            }

            // OR

            void file_readAs(fstream &ifile)
            {
                char extra[45];
                char filename[10];
                cout<<"Enter the file name";
                cin>>filename;
                ifile.open(filename,ios::in);
                while (!ifile.eof())
                {
                    ifile.getline(name,20,'|');
                    ifile.getline(sem,10,'|');
                    ifile.getline(branch,10,'|');
                    ifile.getline(extra,45,'\n');
                    cout<<name<<" "<<sem<<" "<<branch<<endl;
                }
                
            }
};

int main()
{
    int ch;
    student s;
    while(1)
    {
        cout<<"Enter the choice\n 1)Store student data\n 2)read 3)exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            s.read();
            s.file_io(0);
            break;
            case 2:
            s.file_io(1);
            break;
            case 3: exit(0);
            default:cout<<"invalid input\n";
        }
    }
}



#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
    int a, i=0;
    string text,old,password1,password2,pass,name,password0,age,user,word,word1;
    string creds[2], cp[2];
    cout<<"      Security System"<<endl;
    cout<<"______________________________"<<endl<<endl;
    cout<<"           1. Register        "<<endl;
    cout<<"           2. Login           "<<endl;
    cout<<"           3. Change password "<<endl;
    cout<<"___________4. End Program_____"<<endl;
    do
    {
        cout<<endl<<endl;
        cout<<"Enter your choice:- ";
        cin>>a;
        switch(a)
        {
            case 1:{
                cout<<"_______________________"<<endl<<endl;
                cout<<"|---------Register-----|"<<endl<<endl;
                cout<<"_______________________"<<endl<<endl;
                cout<<"Please enter username:-";
                cin>>name;
                cout<<"Please enter the password:-";
                cin>>password0;
                cout<<"Please enter your age:-";
                cin>>age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"Registration successful"<<endl;
                }
                break;
            }
            case 2:{
                i=0;
                cout<<"__________________________"<<endl<<endl;
                cout<<"|----------Login----------|"<<endl;
                cout<<"|_________________________|"<<endl<<endl;
                ifstream of2;
                of2.open("file.txt");
                cout<<"Please enter the username:-";
                cin>>user;
                cout<<"Please enter the password:-";
                cin>>pass;

                if(of2.is_open())
                {
                    while(!of2.eof())
                    {
                        while(getline(of2,text)){
                            istringstream iss(text);
                            iss>>word;
                            creds[i]=word;
                            i++;
                        }
                        if(user==creds[0] && pass==creds[1]){
                            cout<<"---Log in successful---";
                            cout<<endl<<endl;
                            cout<<"Details"<<endl;
                            cout<<"Username: "+ name<<endl;
                            cout<<"Password: "+ pass<<endl;
                            cout<<"Age: "+ age<<endl;
                        }
                        else{
                            cout<<endl<<endl;
                            cout<<"Incorrect Credentials"<<endl;


                        }
                    }
                }
            }

        }
    }
    while(a!=4);
    return 0;
}

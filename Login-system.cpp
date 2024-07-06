#include<iostream>
#include<fstream>
using namespace std;
class Login_system
{
private:
string username,password,name,phone,email,address;
public:
    Login_system(string username,string password,string name,string phone,string email,string address);
    void display();

};

Login_system::Login_system(string username,string password,string name,string phone,string email,string address)
{
    this->username=username;
    this->password=password;
    this->name=name;
    this->phone=phone;
    this->email=email;
    this->address=address;
}
void menu()
{

    cout<<"Select an option"<<endl;
    cout<<"1.Register"<<endl;
    cout<<"2.Login"<<endl;
    cout<<"3.Exit"<<endl;
    int choice;
    cin>>choice;
    if(choice==1){
        cout<<"Enter username: ";
        string username;
        cin>>username;
        cout<<"Enter password: ";
        string password;
        cin>>password;
        cout<<"Enter name: ";
        string name;
        cin>>name;
        cout<<"Enter phone: ";
        string phone;
        cin>>phone;
        cout<<"Enter email: ";
        string email;
        cin>>email;
        cout<<"Enter address: ";
        string address;
        cin>>address;
        Login_system u1(username,password,name,phone,email,address);
        u1.display();
    }
    else if(choice==2){
        cout<<"Enter username: ";
        string username;
        cin>>username;
        cout<<"Enter password: ";
        string password;
        cin>>password;;
        if( username ==u1.password  && u1.password==password){
            cout<<"Login Successful"<<endl;
        }
        else if(choice==3){
        cout<<"\t\tThanks For Using Our System\t\t"<<endl;
        }
        else{
            cout<<"\t\tInvalid Choice\t\t"<<endl;
        }
}
}
void Login_system::display(){
    cout<<"username: "<<username<<endl;
    cout<<"password: "<<password<<endl;
    cout<<"name: "<<name<<endl;
    cout<<"phone: "<<phone<<endl;
    cout<<"email: "<<email<<endl;
    cout<<"address: "<<address<<endl;
}
int main(){
    cout<<"\t\tWelcome to Login System\t\t"<<endl<<endl;
    menu();


    return 0;

}

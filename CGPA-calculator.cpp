#include<iostream>
using namespace std;
int main(){
string name;
int scount;
cout<<"\twelcome to CGPA Calculator"<<endl;
cout<<"Enter Your Name:";
cin>>name;
cout<<"Enter the semester you are in:";
cin>>scount;
for (int  i = 0; i < scount; i++)
{   
    cout<<"\nEnter the number of courses you took in semester "<<i+1<<":";
    int numberofsubjects;
    cin>>numberofsubjects;
    for (int  i = 0; i < numberofsubjects; i++)
    {
    char grade[numberofsubjects];
    int credits[numberofsubjects];
    cout<<"\nEnter the grade in Course "<<i+1<<" with respect to creits earned:";
    cin>>grade[i]>>credits[i];   
     
    }
    

}
return 0;
}
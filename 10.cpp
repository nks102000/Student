/*WAP that reads records of n students and find the

average mark of each student

# of students above average mark in the class.

# of students below average mark in the class.

Sort students in ascending order of their mark.

Display the name of the student secured highest mark.*/
#include<iostream>
#include<string.h>
using namespace std;

class student
{
    char *name;
    int roll;
    int total_marks;
    float avg;
    public:
    void set(char *na,int rl,int marks){
        name=new char[strlen(na)];
        strcpy(name,na);
        roll=rl;
        total_marks=marks;
        avg=total_marks/5;
    }

    void display(){
        cout<<"----------------------------------------------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Roll: "<<roll<<endl;
        cout<<"Total Marks: "<<total_marks<<endl;
        cout<<"Average Marks: "<<avg<<endl;

    }
    void sort(student s[],int n){
        for(int i=0;i<n-1;i++){
            for(int j =i;j<n-i-1;j++){
                if(s[j].total_marks>s[j+1].total_marks){
                    student temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                }
            }
        }
    }
    void number_compare(student s[],int n,float average){
        int high=0;
        int low=0;
        for(int i=0;i<n;i++){
            if(s[i].avg>average){
                high++;
            }
            else if(s[i].avg<average){
                low++;
            }
        }
        cout<<"The number students higher than the average are: "<<high<<endl;
        cout<<"The number students lower than the average are: "<<low<<endl;
    }
};

int main(){
    int n;
    cout<<"Enter number of students you want to enter the detail for:";
    cin>>n;
    student s[n];
    char name[50];
    int roll;
    int total_marks;
    for(int i=0;i<n;i++){
        cout<<"----------------------------------------------"<<endl;
        cout<<"Enter name:";
        cin>>name;
        cout<<"Enter roll:";
        cin>>roll;
        cout<<"Enter marks:";
        cin>>total_marks;
        s[i].set(name,roll,total_marks);
    }
    cout<<"Details before sorting"<<endl;
    for(int i=0;i<n;i++){
        s[i].display();
    }
    cout<<"After sorting"<<endl;
    s[0].sort(s,n);
    for(int i=0;i<n;i++){
        s[i].display();
    }
    cout<<"Enter the Average of class:";
    int f;
    cin>>f;
    s[0].number_compare(s,n,f);
    return 0;
}
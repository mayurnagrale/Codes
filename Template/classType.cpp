#include<bits/stdc++.h>
using namespace std;

class Employee{
    public:
        string Name;
        string Company;
        int Age;

        void IntroduceYourSelf(){
            cout<<"Name->"<<Name<<endl;
            cout<<"Company->"<<Company<<endl;
            cout<<"Age->"<<Age<<endl;
        }
        //constructor
        Employee(string name,string company,int age){
            Name=name;
            Company=company;
            Age=age;
        }
};

class Point{
    int x;
    int y;
    public:
    void setX(int xc){//setters
        x=xc;
    }
    int getX(){//getters
        return x;
    }
    void setY(int yc){//setters
        y=yc;
    }
    int getY(){//getters
        return y;
    }
};

int main(){
    // Employee employee1;
    // employee1.Name = "Mayur";
    // employee1.Company="Self Employeed";
    // employee1.Age = 25;
    // employee1.IntroduceYourSelf();

    //After creating a constructor
    Employee employee1=Employee("Mayur","Self Employeed",25);
    employee1.IntroduceYourSelf();

    //we can create the same in just two lines now
    Employee employee2=Employee("John","Self Employeed",35);
    employee2.IntroduceYourSelf();

    //setting setters and accessing getters
    Point pt1;//=Point(1,2);   
    pt1.setX(2);
    pt1.setY(3);
    cout<<pt1.getX()<<" "<<pt1.getY()<<endl;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Student{ //Blueprint 
    string name;
    float cgpa;

public: 
    //Methods
    void getPercentage(){
        cout<< (cgpa*10) << "% \n";
    }
    
    //Setter Methods
    void setName(string nameVal){
        name = nameVal;
    }
     void setCgpa(float cgpaVal){
        cgpa = cgpaVal;
    }

    //Getter Methods
    string getName(){
        return name;
    }
     float getCgpa(){
        return cgpa;
    }
};


int main() {
    Student s1; //Object
    s1.setName("AKSHAT");
    s1.setCgpa(9.2);

    cout<<s1.getName()<<endl;
    cout<<s1.getCgpa()<<endl;
    s1.getPercentage();
    return 0;
}
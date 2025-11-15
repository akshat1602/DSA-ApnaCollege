#include <iostream>
#include <string>
using namespace std;

class Student{ //Blueprint 
public: //Access Modifier

    //Properties
    string name;
    float cgpa;

    //Methods
    void getPercentage(){
        cout<< (cgpa*10) << "% \n";
    }
};

/* class User{ //Like Insta backend forr users
    int id;
    string username;
    string password;
    string bio;

    void deactivate(){
        cout<<"deleting account!";
    }

    void editBio(string newBio){
        bio = newBio;
    }
};
 */

int main() {
    Student s1; //Object
    s1.name = "Akshat";
    s1.cgpa = 9.0;
    cout<<s1.name<<endl;
    cout<<s1.cgpa<<endl;
    s1.getPercentage();

    cout<<sizeof(s1)<<endl; //Space is allocated only after the creation of objects.
    return 0;
}
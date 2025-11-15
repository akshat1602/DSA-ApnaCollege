#include <iostream>
#include <vector>
using namespace std;

class Teacher{
    public:
    int salary;
    string subject;
};

class Student{
    public:
    int rollno;
    float cgpa;
};

class TA : public Teacher, public Student{
    public:
    string name;
};

int main() {
    TA t1;
    t1.name = "Akshat Trivedi";
    t1.subject = "OS";
    t1.rollno = 104;
    t1.cgpa = 9.2;
    t1.salary = 100000;

    cout<<t1.name<<endl;
    cout<<t1.subject<<endl;
    cout<<t1.rollno<<endl;
    cout<<t1.cgpa<<endl;
    cout<<t1.salary<<endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Student{
public:
    string name;
    int marks;

    Student(string name, int marks){
        this->name = name;
        this->marks = marks;
    }
    
    //operator overloading : to make cutom comparitor to compare values
    // on the basis of particular attribute
    bool operator < (const Student &obj) const{ //default-> maxheap, for minheap use : '>'.
        return this->marks < obj.marks;
    }
};

int main() {
    priority_queue <Student> pq;

    pq.push(Student("Akshat", 90));
    pq.push(Student("Aman", 89));
    pq.push(Student("Alfee", 94));
    pq.push(Student("Amartya", 97));

    while(!pq.empty()){ //descending order mein aaega
        cout<<"Top : "<<pq.top().name<<", "<<pq.top().marks<<endl;
        pq.pop();
    }
    return 0;
}
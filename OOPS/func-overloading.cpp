#include <iostream>
#include <vector>
using namespace std;

class Print{
    public:
    void show(int a){
        cout<<"Int : "<<a<<endl;
    }

    void show(string b){
        cout<<"String : "<<b<<endl;
    }
};

int main() {
    Print ob1;
    ob1.show(50);
    ob1.show("akshat");
    return 0;
}
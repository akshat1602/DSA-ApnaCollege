#include <iostream>
using namespace std;

class Shape{ //Abstract class: no objects can be created.
    public:
    virtual void draw() = 0; //Pure Virtual fun/abstract func
};

class Square : public Shape{
    public:
    void draw() {
        cout<<"Square gets drawn\n";
    }
};

class Cube : public Shape{
    public:
    void draw() {
        cout<<"Cube gets drawn\n";
    }
};

int main() {
    Square s1;
    s1.draw();

    Cube c1;
    c1.draw();
    
    return 0;
}
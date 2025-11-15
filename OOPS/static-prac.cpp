#include <iostream>
using namespace std;

void counter(){
    static int count = 0; //as its static it wont reinitialize on other calls after the 1st func call.
    count++;
    cout<<"Count : "<<count<<endl; 
}

class Example{
    public:
    static int x; // declaration only inside the class as its not constant.
};

int Example::x=0;// initialization of x. x ka declaration example class ke andar hai.

int main() {
    //Objects
    Example eg1;
    Example eg2;
    Example eg3; // as now all the objects are sharing the same x in the memory location.

    cout<<eg1.x++<<endl;
    cout<<eg1.x++<<endl;
    cout<<eg1.x++<<endl;

    //Functions
    counter();
    counter();
    counter();
    
    return 0;
}
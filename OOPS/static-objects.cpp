#include <iostream>
using namespace std;

class Example{
    public:
    Example(){
        cout<<"Constructor..\n";
    }

    ~Example(){
        cout<<"Destructor..\n";
    }
};


int main() {
    int a = 0;
    if(a==0){
        static Example eg1; // due to static last mein destr. run karega jab pura code ends.
    }
    cout<<"Code Ending\n";
    
    return 0;
}
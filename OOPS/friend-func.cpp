#include <iostream>
using namespace std;

class A{
    string secret = "secret info."; //Private data member
    friend class B; // Now the above data can be accessed
    friend void revealSecret(A &obj); //full function signature with friend keyword to access by functions.
};

class B{ //Becomes friend class of A.
    public:
    void showSecret(A &obj){
        cout<<obj.secret<<endl;
    }
};

void revealSecret(A &obj){
    cout<<obj.secret<<endl;
}

int main() {
    A a1;
    B b1;

    b1.showSecret(a1);
    
    return 0;
}
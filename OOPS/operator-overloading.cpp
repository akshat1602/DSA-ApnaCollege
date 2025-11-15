#include <iostream>
#include <vector>
using namespace std;

class Complex{
    public:
    int real;
    int img;

    Complex(int r, int i){
        real = r;
        img = i;
    }

    void showNum(){
        cout<<real << "+" << img<< "i" << endl;
    }

    void operator + (Complex &c2) { //imp. : Operator overloading
        int resReal = this->real + c2.real;
        int resImg = this->img + c2.img;

        Complex c3(resReal, resImg); //resultant object holding the sum of complex numbers.
        cout<<"Result : ";
        c3.showNum();
    }

};

int main() {
    Complex c1(1,2);
    Complex c2(3,4);

    c1.showNum();
    c2.showNum();

    c1 + c2; //operator over. tabhi error nhi aai.
    return 0;
}
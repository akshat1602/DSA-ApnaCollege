#include <iostream>
using namespace std;

char printChar(char a){
    if(a=='z'){
        return 'a';
    }
    else{
        char ch = a + char(1);
        return ch;
    }
}

int main() {
    char ch;
    cout<<"Enter a character : "<<endl;
    cin>>ch;

    cout<<"Next character is : "<<printChar(ch)<<endl;

    return 0;
}
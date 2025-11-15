//Important ques ---> x^n

#include <iostream>
#include <vector>
using namespace std;

int fastExpo(int x, int n){
    int ans = 1;

    while(n > 0){ //power ke bits par work

        int lastBit = n&1;

        if(lastBit){//meaning 1
            ans*=x;
        }
        x = x*x; //squaring the base
        n = n>>1;
    }

    return ans;
}

int main() {
    int x,n;
    cout<<"enter the number and power : "<<endl;
    cin>>x>>n;
    
    cout<<fastExpo(x,n)<<endl;
    return 0;
}
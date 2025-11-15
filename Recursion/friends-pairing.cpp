#include <iostream>
#include <vector>
using namespace std;

int friendsPair(int n){
    if(n == 1 || n == 2) return n;

/*  //single
    friendsPair(n-1);

    //pair
    (n-1) * friendsPair(n-2); */

    return friendsPair(n-1) + (n-1) * friendsPair(n-2);
}

int main() {
    int n;
    cout<<"enter a number : "<<endl;
    cin>>n;

    cout<<"Ways : "<<friendsPair(n)<<endl;
    
    return 0;
}
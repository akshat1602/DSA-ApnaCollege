#include <iostream>
#include <vector>
using namespace std;

int tilingProb(int n){ //2xn
    //Base Case
    if(n==0 || n==1) return 1;
    
    //vertical
    int ans1 = tilingProb(n-1); //2xn-1

    //horizontal
    int ans2 = tilingProb(n-2); //2xn-2

    return ans1 + ans2;

}

int main() {
    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    cout<<"Ways to fill floor are : "<<tilingProb(n)<<endl;
    return 0;
}
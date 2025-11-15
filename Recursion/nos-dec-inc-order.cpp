#include <iostream>
using namespace std;

void decreasing(int n){ // n=5, 5 4 3 2 1.
    if(n == 0) return;

    cout<<n<<" ";
    decreasing(n-1);
}

void increasing(int n){ // n=5, 1 2 3 4 5.
    if(n == 0) return;
    
    increasing(n-1); //pehle chota horha then bada.
    cout<<n<<" ";
}

int main() {
    int n;
    cout<<"enter input : "<<endl;
    cin>>n;
    decreasing(n);
    cout<<"\n";
    increasing(n);
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int power2(int num){ //here bitmask is num-1. 
   if (!(num&(num-1))) return true;
   else return false;
}

int main() {
    int num, i;
    cout<<"enter the number : "<<endl;
    cin>>num;
    
    cout<<power2(num)<<endl;
  
    return 0;
}
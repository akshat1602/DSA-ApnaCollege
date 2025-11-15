#include <iostream>
#include <vector>
using namespace std;

int countSet(int num){
    int sum = 0; //count wala
    
    while(num>0){
        int lastDig = num&1;
        sum+=lastDig; //sirf 1 wali hi add up hongi

        num = num>>1; //to iterate over the remaining digits
    }

    return sum;
}

int main() {
    int num;
    cout<<"enter the number : "<<endl;
    cin>>num;
    
    cout<<countSet(num)<<endl;
    return 0;
}
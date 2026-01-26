#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void pushAtBottom(stack <int> &s, int val){ //O(n)
    if(s.empty()){ //base case
        s.push(val); //push at the bottom of stack
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}


int main() {
    stack <int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    pushAtBottom(s, 4);
    
    cout<<"Order of elements popped :"<<" ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}
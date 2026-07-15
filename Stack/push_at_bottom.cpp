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

void pushAtBottomIterative(stack <int> &s, int val){
    stack <int> temp; //temp stack to store elements

    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }

    s.push(val); //at bottom of stack

    // Move back from temp to original
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}


int main() {
    stack <int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    // pushAtBottom(s, 4);
    pushAtBottomIterative(s, 5);
    
    cout<<"Order of elements popped :"<<" ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}
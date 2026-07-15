#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Using vector
class Stack{
    vector <int> vec;
    public:
        void push(int val){ //push in stack
            vec.push_back(val);
        }

        void pop(){ //pop from stack
            if(isEmpty()){
                cout<<"Stack Empty!"<<endl;
                return;
            }
            vec.pop_back(); //if not empty.
        }

        int top(){ //to find TOS
            if(isEmpty()){
                cout<<"Stack Empty!"<<endl;
                return -1;
            }

            int lastIdx = vec.size()-1;
            return vec[lastIdx];
        }
        
        bool isEmpty(){//to check empty or not.
            return vec.size() == 0;
        }
};

void pushAtBottom(stack <int> &s, int val){
            if(s.empty()){
                s.push(val);
                return;
            }

            int temp = s.top();
            s.pop();
            pushAtBottom(s, val);
            s.push(temp);
        }


int main() {
    Stack s;
    stack <int> s1;

    s.push(3);
    s.push(2);
    s.push(1);
    s.push(0);

    s1.push(3);
    s1.push(2);
    s1.push(1);

    pushAtBottom(s1, 4);

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    
    return 0;
}
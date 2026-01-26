#include <iostream>
#include <vector>
using namespace std;

//create stack using vector with class template
template <class T>
class Stack{
    vector<T> vec;
    public:
      void push(T val){ //O(1)
        vec.push_back(val);
      }

      void pop(){ //O(1)

        if(isEmpty()){ //underflow condition check
            cout<<"Stack Empty!"<<endl;
            return;
        }
        vec.pop_back();

      }

      T top(){ //O(1)

/*         if(isEmpty()){ //underflow condition check
            cout<<"Stack Empty!"<<endl;
            return -1;
        } */
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];

      }

      bool isEmpty(){ //O(1)
        return vec.size() == 0;
      }
};

int main() {
    Stack <char> s; //defines that what type of values will be stored

    s.push('c');
    s.push('b');
    s.push('a');

    cout<<"Order of elements popped :"<<" ";
    while (!s.isEmpty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    
    return 0;
}
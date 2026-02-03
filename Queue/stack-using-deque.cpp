#include <iostream>
#include <deque>
using namespace std;

class Stack
{//for front execution
    deque <int> deq;

public:
    void push(int data)
    {
        deq.push_front(data);
    }

    void pop()
    {
        deq.pop_front();
    }

    int top()
    {
        return deq.front();
    }

    bool empty()
    {
        return deq.empty();
    }
};

class Stack2
{ //for back execution
    deque <int> deq;

public:
    void push(int data)
    {
        deq.push_back(data);
    }

    void pop()
    {
        deq.pop_back();
    }

    int top()
    {
        return deq.back();
    }

    bool empty()
    {
        return deq.empty();
    }
};


int main()
{
    Stack s;
    Stack2 s1;

    for (int i = 1; i <= 5; i++)
    {
        s1.push(i);
    }
    
    for (int i = 1; i <= 5; i++)
    {
        cout << s1.top()<<" ";
        s1.pop();
    }

    return 0;
}
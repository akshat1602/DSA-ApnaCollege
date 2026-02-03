#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque <int> deq;

    deq.push_front(2);
    deq.push_front(1);

    deq.push_back(3);
    deq.push_back(4);

    deq.pop_front();//1 popped
    deq.pop_back(); //4 popped

    cout<<deq.front()<<" ";
    cout<<deq.back();
    return 0;
}
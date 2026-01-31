#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void queueRev(queue <int> &orig){
    stack <int> s;
    
    //queue to stack
    while(!orig.empty()){
        s.push(orig.front());
        orig.pop();
    }

    //stack to queue -> reversed order
    while(!s.empty()){
        orig.push(s.top());
        s.pop();
    }
}

int main() {
    queue <int> original;
    for (int i = 1; i <= 5; i++)
    {
        original.push(i);
    }

    queueRev(original);

    for (int i = 1; i <= 5; i++)
    {
        cout<<original.front()<<" ";
        original.pop();
    }
    cout<<endl;

    return 0;
}
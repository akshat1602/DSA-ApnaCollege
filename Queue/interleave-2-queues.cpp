#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void interleave(queue <int> &original){ //O(n)
    int n = original.size();
    queue <int> first;

    for (int i = 0; i < n/2; i++) //for storing 1st half in first queue
    {
        first.push(original.front());
        original.pop();
    }

    while (!first.empty()) //interleaving loop
    {
        original.push(first.front());
        first.pop();

        original.push(original.front());
        original.pop();
    }  
}

int main() {
    queue <int> original;

    for (int i = 1; i <= 10; i++)
    {
        original.push(i);
    }

    interleave(original); //function to perform interleave

    for (int i = 1; i <= 10; i++)
    {
        cout<<original.front()<<" ";
        original.pop();
    }
    cout<<endl;

    return 0;
}
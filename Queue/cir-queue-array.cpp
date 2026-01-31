#include <iostream>
#include <vector>
using namespace std;

class Queue{
    int *arr;

    int capacity; // total size of array
    int currSize; // number of elements currently in array.

    int f, r; // front and rear

public:
    Queue(int capacity){ 
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0; //no element 
        
        f = 0;
        r = -1;
    }

    void push(int data){ //O(1)
        if(currSize == capacity){ //overflow check
            cout<<"Queue is FULL\n";
            return;
        }

        r = (r+1) % capacity;
        arr[r] = data;
        currSize++; //updation
    }

    void pop(){ //O(1)
        if(empty()){ //underflow check
            cout<<"Queue is EMPTY\n";
            return; 
        }

        f = (f + 1) % capacity;
        currSize--;
    }

    int front(){ //O(1)
        if(empty()){ 
            cout<<"Queue is EMPTY\n";
            return -1; 
        }

        return arr[f];
    }

    bool empty(){
        return currSize == 0;
    }

    void printRear(){
        cout<<arr[r]<<endl;
    }
};

main()
{
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<< q.front() <<endl; //1
    q.pop();
    cout<< q.front() <<endl; //2
    q.push(5);
    q.pop();
    cout<< q.front() <<endl; //3

    q.printRear(); //5

    return 0;
}
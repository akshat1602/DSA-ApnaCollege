#include <iostream>
#include <vector>
using namespace std;

class Heap
{
    vector<int> vec; // CBT

public:
    void push(int val)
    {
        // step-1
        vec.push_back(val);

        // fix heap
        int x = vec.size() - 1; // childIdx
        int parIdx = (x - 1) / 2;
        
        //for min heap :  vec[x] < vec[parIdx]
        while (parIdx >= 0 && vec[x] > vec[parIdx]) //max heap case
        { // O(logn)
            swap(vec[x], vec[parIdx]);
            x = parIdx;
            parIdx = (x - 1) / 2;
        }
    }

    void pop(){

    }

    int top(){
        return vec[0]; //highest priority element
    }

    bool empty(){
        return vec.size() == 0; //if empty then true
    }
};

int main()
{
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    cout<<"Top = "<<heap.top()<<endl;

    return 0;
}
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

    void heapify(int i){ //i = parIdx

        if(i >= vec.size()){ //when elements are not there
            return;
        }

        int left = 2*i+1;
        int right = 2*i+2;

        int maxIdx = i;
        if(left < vec.size() && vec[left] > vec[maxIdx]){ //if left is bigger
            maxIdx = left;
        }

        if(right < vec.size() && vec[right] > vec[maxIdx]){ //if right is bigger
            maxIdx = right;
        }

        swap(vec[i], vec[maxIdx]);
        if(maxIdx != i){ //swapping with child node
            heapify(maxIdx);
        }
    }

    void pop(){
        //step-1
        swap(vec[0], vec[vec.size()-1]);

        //step-2
        vec.pop_back();

        //step-3
        heapify(0); // O(logn)
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
    heap.push(9);
    heap.push(4);
    heap.push(8);
    heap.push(1);
    heap.push(2);
    heap.push(5);

    while(!heap.empty()){
        cout<<"Top : "<<heap.top()<<endl;
        heap.pop();
    }

    return 0;
}
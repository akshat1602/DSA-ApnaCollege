//FREEING THE HEAP SPACE

//To avoid memory leak --> when programmer forgets to free up memory space
//leads to performance degradation due to depletion of available memory

#include <iostream>
using namespace std;

void funcInt(){ //For single value
    int *ptr = new int;
    *ptr = 5;
    cout<<*ptr;//jiski trf "ptr" point karrha uska data print kardo.

    delete ptr; //keyword to free memory
}

void func(){ //For array
    int size;
    cout<<"enter size : "<<endl;
    cin>>size;

    int *ptr = new int[size]; //right side dynamic memory inside heap.

    int x = 1;

    for (int i = 0; i < size; i++)
    {
        ptr[i] = x;
        cout<<ptr[i]<<" ";
        x++;
    }
    cout<<endl;

    delete[] ptr; //array ko delete karne wala syntax.
    // to free memory for future programs 
    //to avoid memory leak
}

int main() {
    func();
    funcInt();

    return 0;
}
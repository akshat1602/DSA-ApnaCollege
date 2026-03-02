#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    priority_queue <int> pq; //max heap
    priority_queue <int, vector <int>, greater<int>> pq2; //min heap
    priority_queue <string, vector <string>, greater<string>> pq3; //min heap : string

    pq.push(10);
    pq.push(9);
    pq.push(14);
    pq.push(2);

    pq2.push(10);
    pq2.push(9);
    pq2.push(14);
    pq2.push(2);
    
    pq3.push("akshat");
    pq3.push("alfee");
    pq3.push("amartya");
    pq3.push("aman");

    while(!pq.empty()){
        cout<<"Top : "<<pq.top()<<endl;
        pq.pop();
    }
    
    cout<<"------------------"<<endl;

    while(!pq2.empty()){
        cout<<"Top : "<<pq2.top()<<endl;
        pq2.pop();
    }
    
    cout<<"------------------"<<endl;

    while(!pq3.empty()){
        cout<<"Top : "<<pq3.top()<<endl;
        pq3.pop();
    }
    
    return 0;
}
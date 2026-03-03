#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//yahan bhi operator overloading hota bas in the struct yaha hota
//same objects ki trh bas different way
struct comparePair{
    bool operator() (pair <string, int> &p1, pair <string, int> &p2){
        return p1.second < p2.second; //default -> maxheap
    }
};

int main() {
    priority_queue <pair<string, int>, vector <pair<string, int>>, comparePair> pq;

    pq.push(make_pair("Akshat", 90));
    pq.push(make_pair("Aman", 89));
    pq.push(make_pair("Alfee", 94));
    pq.push(make_pair("Amartya", 97));

    while(!pq.empty()){ //descending order mein aaega
        cout<<"Top : "<<pq.top().first<<", "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}
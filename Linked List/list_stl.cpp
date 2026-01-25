#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

void printList(list<int> ll){
    list <int> :: iterator itr; //creation of iterator
    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout<< *(itr) << "->";
    }
    cout<<"NULL\n";
}

int main() {
    list <int> ll; //like: vector <int> arr

    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(3);
    ll.push_back(4);

    printList(ll);
    cout<<ll.size()<<endl;

    cout<<"head = "<<ll.front()<<endl;
    cout<<"tail = "<<ll.back()<<endl;
    
    list<int> :: iterator it = ll.begin();
    ll.insert(it, 2, 7); //stores/inserts 2 occurences of 7 at the beginning
    printList(ll);

    list<int> :: iterator it1 = ll.end();
    ll.insert(it1, 3, 8); //stores/inserts 3 occurences of 8 at the beginning
    printList(ll);
    
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//Similar to unordered maps with O(1) TC.
int main()
{
    unordered_set<int> s;

    s.insert(1);
    s.insert(4);
    s.insert(5);
    s.insert(2);
    s.insert(3);
    s.insert(1); //duplication not allowed

    cout<<"Size : "<<s.size()<<endl; //5 aaega coz 1 phirse add nhi hoga in set

    s.erase(3);
    cout<<"Size : "<<s.size()<<endl;

    if(s.find(2) != s.end()){
        cout<<"2 exists\n";
    }
    else{
        cout<<"2 doesnt exist\n";
    }

    for(auto el : s){
        cout<<el<<" ";
    }

    return 0;
}
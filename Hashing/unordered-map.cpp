#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Order wont be maintained but will be faster than maps
int main() { //O(1) TC

    //Basic syntax and insertion of elements
    unordered_map<string, int> m;
    m["China"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["UK"] = 20;
    m["Nepal"] = 10;

    for(pair <string, int> country : m){
        cout<<country.first<<", "<<country.second<<endl;
    }

    //erase function
    m.erase("UK"); 

    //count function
    if(m.count("Nepal")){
        cout<<"Nepal exists"<<endl;
    }
    else{
        cout<<"Nepal doesn't exist"<<endl;
    }

    cout<<"--------\n";
    for(pair <string, int> country : m){
        cout<<country.first<<", "<<country.second<<endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printSubsets(string str, string subset){
    int n = str.size();
    if(n == 0){
        cout<<subset<<"\n";
        return;
    }

    char ch = str[0];

    //Yes case
    printSubsets(str.substr(1, n-1), subset+ch);

    //No case
    printSubsets(str.substr(1, n-1), subset);
}

int main() {
    string str = "abc";
    string subset = "";

    printSubsets(str, subset);
    return 0;
}
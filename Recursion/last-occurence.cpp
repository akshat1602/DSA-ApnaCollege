#include <iostream>
#include <vector>
using namespace std;

int lastOccu(vector <int> a, int target, int i){
    if(i == a.size()){ //Base Case.
        return -1;
    } 
    
    int idxFound = lastOccu(a, target, i+1); //recursion baad se karoge yahan.

    if(idxFound == -1 && a[i] == target){ //phir pehle wala check if -1 aaya aage se.
            return i;
        }
        return idxFound;
    }

int main() {
    vector <int> a = {1,2,3,3,3,4};
    int target;
    cout<<"Enter the target : "<<endl;
    cin>>target;

    cout<<lastOccu(a, target, 0)<<endl;
    
    return 0;
}

/* Revision: Recursion - lastOccu call-stack (target = 3)
   Array: {1,2,3,3,3,4}

   Visualization table:
   Frame (i) | a[i] | idxFound (from recursion) | Condition (idxFound == -1 && a[i] == target) | Returned value
   -----------------------------------------------------------------------------------------------
   base i=6  |  -   | -1                        | n/a                                             | -1
   i = 5     |  4   | -1                        | false                                           | -1
   i = 4     |  3   | -1                        | true                                            | 4
   i = 3     |  3   | 4                         | false                                           | 4
   i = 2     |  3   | 4                         | false                                           | 4
   i = 1     |  2   | 4                         | false                                           | 4
   i = 0     |  1   | 4                         | false                                           | 4

   Final returned index: 4  (0-based) — the last occurrence of 3.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

void printUnion(vector <int> nums1, vector <int> nums2){
    unordered_set <int> s;

    for(int el : nums1){
        s.insert(el);
    }
    for(int el : nums2){
        s.insert(el);
    }

    //print union
    cout<<"Union is : ";
    for(int el : nums2){
        cout<<el<<" ";
    }
    cout<<endl;
}

void printIntersection(vector <int> nums1, vector <int> nums2){
    unordered_set <int> s;

    for(int el : nums1){
        s.insert(el);
    }

    //Print Intersection
    cout<<"Intersection is : ";
    for(int el : nums2){
        if(s.find(el) != s.end()){//Found
            cout<<el<<" ";
            s.erase(el); //erase so that no repeatation happens.
        }
    }
}

int main() {
    vector <int> nums1 = {7, 3, 9};
    vector <int> nums2 = {6, 3, 9, 2, 9, 4};

    printUnion(nums1, nums2);
    printIntersection(nums1, nums2);
    
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

bool validAnagram(string s, string t){
    //for unequal strings
    if(s.size() != t.size()) return false;

    //s <char, freq>
    unordered_map <char, int> freq;
    for (int i = 0; i < s.size(); i++)
    {
        if(freq.count(s[i])){ //if it already exists
            freq[s[i]]++;
        }
        else{
            freq[s[i]] = 1;
        }
    }

    //2nd to look for t's chars in freq
    for (int i = 0; i < t.size(); i++)
    {
        if(freq.count(t[i])){
            freq[t[i]]--;
            if(freq[t[i]] == 0){//remove from map
                freq.erase(t[i]);
            }
        }
        else{
            return false;
        }
    }

    return freq.size() == 0; //true -> 0, else -> false
}

int main() {
    string s = "race";
    string t = "care";

    cout<<validAnagram(s,t)<<endl;
    
    return 0;
}
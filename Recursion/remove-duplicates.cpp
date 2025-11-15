#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicates(string str, string ans, int i, int map[26]){
    if(i == str.size()){ //Base Case.
        cout<<"ans : "<<ans<<endl;
        return;
    }

    char ch = str[i];
    int mapIdx = (int)(ch-'a'); //typecasting : 'a' -> 0, 'b'-> 1....

    if(map[mapIdx] == true){ //Duplicates
        removeDuplicates(str, ans, i+1, map);
    }
    else{ // nOt duplicate
        map[mapIdx] = true; //changing the value to true that we got the element now.
        removeDuplicates(str, ans+str[i], i+1, map);
    }
}


void removeDuplicates2(string str, string ans, int map[26]){ //Without passing index
    if(str.size() == 0){ //Base Case. : string ko chota karrhe peeche se tabhi.
        cout<<"ans : "<<ans<<endl;
        return;
    }

    int n = str.size();
    char ch = str[n-1];
    int mapIdx = (int)(str[n-1]-'a'); //typecasting : 'a' -> 0, 'b'-> 1....
    str = str.substr(0, n-1); //took out the substring to pass onto the next call.

    if(map[mapIdx] == true){ //Duplicates
        removeDuplicates2(str, ans, map);
    }
    else{ // Not duplicate
        map[mapIdx] = true; //changing the value to true that we got the element now.
        removeDuplicates2(str, ch+ans, map);
    }
}

int main() {
    string str = "appnnacollege";
    string ans = "";
    int map[26] = {false};

    removeDuplicates(str, ans, 0, map);

    // reset the map before the second call so previous marks don't affect it
    int map2[26] = {false};
    removeDuplicates2(str, ans, map2);
    
    return 0;
}
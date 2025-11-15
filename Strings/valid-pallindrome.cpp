#include <iostream>
#include <cstring>
using namespace std;

bool checkPallin(char word[], int len){
    int st = 0, end = len-1;
    while(st<end){
        if(word[st++] != word[end--]){
            cout<<"not pallindrome \n";
            return false;
        }
    } 
   cout<<"valid pallindrome \n";
   return true;
}

int main() {
    char word[] = "racecar";
    checkPallin(word, strlen(word));
    
    return 0;
}
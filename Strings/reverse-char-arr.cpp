#include <iostream>
#include <cstring>
using namespace std;

void reverse(char word[], int len){
    int st = 0, end = len-1;
    while(st<end){
        swap(word[st++], word[end--]);
    }
}

int main() {
    char word[] = "akshat"; 
    
    reverse(word, strlen(word));
    cout<<word<<endl;
    return 0;
}
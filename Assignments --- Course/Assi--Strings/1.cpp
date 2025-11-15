#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void countLowerVowels(char arr[], int n){
    int cntvowel = 0;

    for (int i = 0; i < n; i++)
    {
        char ch = arr[i];
 /*  // if kahe to convert the string.
        if(ch>='a' && ch<='z'){ 
        continue;
       }
       else{
        //converted to lowercase.
        arr[i] = ch - 'A' + 'a';
       } */

       if(ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u'){
        cntvowel++;
       }
    }

    cout<<"Number of lowercase vowels are : "<<cntvowel<<endl;
    
}

int main() {
    char arr[] = "aPPLeBiGAAooe";
    countLowerVowels(arr, strlen(arr));
    return 0;
}
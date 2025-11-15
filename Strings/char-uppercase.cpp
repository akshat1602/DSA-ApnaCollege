#include <iostream>
#include <cstring>
using namespace std;

void toUpper(char word[], int n){
    for (int i = 0; i < n; i++)
    {
        char ch = word[i];

        if(ch>='A' && ch<='Z'){ //already uppercase
            continue;
        }
        else{ //lowercase to uppercase
            word[i] = ch - 'a' + 'A'; //position***
        }
    }   
}

void toLower(char word[], int n){
    for (int i = 0; i < n; i++)
    {
        char ch = word[i];

        if(ch>='a' && ch<='z'){ //already lowercase
            continue;
        }
        else{ //uppercase
            word[i] = ch - 'A' + 'a'; //position***
        }
    }   
}

int main() {
    char word1[] = "ApPle";
    char word2[] = "abDee";
    toUpper(word1, strlen(word1));
    toLower(word2, strlen(word2));

    cout<<word1<<endl;
    cout<<word2<<endl;
    return 0;
}
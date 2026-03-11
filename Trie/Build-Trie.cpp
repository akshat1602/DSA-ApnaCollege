#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Node{
public:
      unordered_map <char, Node*> children;
      bool endOfWord;

      Node(){
        endOfWord = false;
      }
};

class Trie{
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string key){ // level wise and letter wise : O(L)
        Node* temp = root;

        for(int i = 0; i<key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node(); //inserting the new character
            }
            temp = temp->children[key[i]]; //changing the level
        }

        temp->endOfWord = true;
    }

    bool search(string key){
        Node* temp = root;

        for(int i = 0; i<key.size(); i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            }
            else{
                return false;
            }
        }
        return temp->endOfWord;
    }
};

int main() {
    vector <string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;

    //insert
    for (int i = 0; i < words.size(); i++)
    {
        trie.insert(words[i]);
    }

    //search
    cout<<trie.search("their")<<endl;

    return 0;
}
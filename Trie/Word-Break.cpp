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

bool helper(Trie &trie, string key){
    if(key.size() == 0){ //BC
        return true;
    }
    
    for(int i = 0; i<key.size(); i++){
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        if(trie.search(first) && helper(trie, second)){
            return true; 
        }
    }

    return false;

}

bool wordBreak(vector <string> dict, string key){
    Trie trie;

    for(int i = 0; i<dict.size(); i++){
        trie.insert(dict[i]); 
    }

    return helper(trie, key);
}

int main() {
    vector <string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
    cout<<wordBreak(dict, "ilikesamsung")<<endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Node{
public:
      unordered_map <char, Node*> children;
      bool endOfWord;
      int freq;

      Node(){
        endOfWord = false;
      }
};

class Trie{
    Node* root;

public:
    Trie(){
        root = new Node();
        root->freq = -1; //root ki freq -1 hogi kyuki woh use nhi hoga
    }

    void insert(string key){ // level wise and letter wise : O(L)
        Node* temp = root;

        for(int i = 0; i<key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node(); //inserting the new character
                temp->children[key[i]]->freq = 1; //if new 
            }
            else{
                temp->children[key[i]]->freq++; //increase count if already exists
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

    string getPrefix(string key){
        Node* temp = root;
        string prefix = "";

        for(int i = 0; i<key.size(); i++){
            prefix += key[i];
            if(temp->children[key[i]]->freq == 1){
                break;
            }
            temp = temp->children[key[i]];
        }

        return prefix;
    }
};

void prefixProblem(vector <string> dict){ //O(n*L)
    Trie trie;

    for(int i = 0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }

    for(int i = 0; i<dict.size(); i++){
        cout<<trie.getPrefix(dict[i])<<" "; //to get prefix
    }
}

int main() {
    vector <string> dict = {"zebra", "dog", "duck", "dove"};

    prefixProblem(dict);
    
    return 0;
}
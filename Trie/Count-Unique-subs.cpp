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

    int countHelper(Node* root){
        int ans = 0;

        for(pair <char, Node*> child : root->children){
            ans += countHelper(child.second); //recursively calling next node
        }

        return ans + 1; //+1 for including the " " string as well.
    }

    int countNodes(){
        return countHelper(root);
    }
};

int countUniqueSubs(string str){
    Trie trie;
    
    //Find suffix
    for(int i = 0; i<str.size(); i++){
        string suffix = str.substr(i);
        trie.insert(suffix);
    }

    return trie.countNodes();
}

int main() {
    string str = "abcd";
    
    cout<<"Unique Substrings : "<<countUniqueSubs(str)<<endl;
    
    return 0;
}
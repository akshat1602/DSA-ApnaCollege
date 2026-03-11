#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
    bool endOfWord;

    Node()
    {
        endOfWord = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string key)
    { // level wise and letter wise : O(L)
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
            {
                temp->children[key[i]] = new Node(); // inserting the new character
            }
            temp = temp->children[key[i]]; // changing the level
        }

        temp->endOfWord = true;
    }

    bool search(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]))
            {
                temp = temp->children[key[i]];
            }
            else
            {
                return false;
            }
        }
        return temp->endOfWord;
    }

    bool startsWith(string prefix) //O(L)
    {
        Node *temp = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            if (temp->children[prefix[i]])// means it is in trie
            {                                     
                temp = temp->children[prefix[i]]; // move next level
            }
            else{
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<string> words = {"apple", "app", "mango", "man", "woman"};
    Trie trie;
    string prefix = "app";

    for (int i = 0; i < words.size(); i++)
    {
        trie.insert(words[i]);
    }

    cout<<trie.startsWith(prefix)<<endl;
    

    return 0;
}
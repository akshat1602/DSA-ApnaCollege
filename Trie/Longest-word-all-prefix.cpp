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

    string longestHelper(Node *root, string &ans, string temp)
    { // IMP
        for (pair<char, Node *> child : root->children)
        {
            if (child.second->endOfWord)
            {
                temp += child.first;

                // Lexicographically smallest selected
                if ((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size()))
                {
                    ans = temp;
                }

                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size() - 1);
            }
        }
    }

    string longestStringWithEOW()
    {
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }
};

string longestString(vector<string> dict)
{
    Trie trie;

    for (int i = 0; i < dict.size(); i++)
    {
        trie.insert(dict[i]);
    }

    return trie.longestStringWithEOW();
}

int main()
{
    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    cout << longestString(dict) << endl;

    return 0;
}
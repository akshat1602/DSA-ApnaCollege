#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
public:
      string key;
      int val;
      Node* next;

      Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
      }

      ~Node() { //destructor for deleting multiple nodes on the same index
        if(next != NULL){
            delete next;
        }
      }
};

class HashTable{
    int totalSize;
    int currSize; //for rehashing
    Node** table;

    int hashFunction(string key){
        int idx = 0;

        for (int i = 0; i < key.size(); i++)
        {
            idx += (key[i] * key[i])%totalSize;//to avoid overflow
        }

        return idx; //yahan the new node will be inserted
    }

    void rehash(){ //O(n)
        
        //to keep original values
        Node** oldTable = table;
        int oldSize = totalSize;

        totalSize = 2*totalSize;
        table = new Node*[totalSize];

        for (int i = 0; i < totalSize; i++)
        {
            table[i] = NULL;
        }

        //copy old values
        for (int i = 0; i < oldSize; i++)
        {
            Node* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }
        delete[] oldTable; //puri original table deleted
    }

public:
    HashTable(int size = 5){ //default sizing
        totalSize = size;
        currSize = 0;

        table = new Node*[totalSize];

        for (int i = 0; i < totalSize; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, int val){ // TC : O(1) Avg
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);
        Node* head = table[idx];

        newNode->next = head;
        head = newNode;

        currSize++;

        double lambda = currSize/(double)totalSize;

        if(lambda > 1){
            rehash(); //O(n) - worst case for insert
        }
    }

    void remove(string key){

    }

    int search(string key){

    }
};

int main() {
    HashTable ht;
    
    return 0;
}
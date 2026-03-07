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

        return idx % totalSize; //yahan the new node will be inserted
    }

    void rehash(){ //O(n)
        
        //to keep original values
        Node** oldTable = table;
        int oldSize = totalSize;

        totalSize = 2*totalSize;
        currSize = 0;
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

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize/(double)totalSize;

        if(lambda > 1){
            rehash(); //O(n) - worst case for insert
        }
    }

    bool exists(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){ //Found
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){ //Found
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }

    void remove(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;

        while(temp != NULL){ //O(lambda)
            if(temp->key == key){ //remove
                if(prev == temp){ //on head
                    table[idx] = temp->next;
                }
                else{
                    prev->next = temp->next; //middle element
                }
                break;
            }

            prev = temp;
            temp = temp->next;
        }

    }

    void print(){
        for (int i = 0; i < totalSize; i++)
        {
            cout<<"idx"<<i<<"->";
            Node* temp = table[i];
            while(temp != NULL){
                cout<<"("<<temp->key<<", "<<temp->val<<") -> ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("USA", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    ht.remove("China");
    ht.print();
    cout<<"---------\n";
    ht.remove("UK");
    ht.print();
    
    return 0;
}
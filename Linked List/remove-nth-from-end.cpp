//SC : O(1) -> in-place reversal

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Node{ 
public : 
    int data;
    Node* next;

     Node(int val){
        data = val;
        next = NULL;
     }
};

class List{
    Node* head;
    Node* tail;

public:
     List(){
        head = NULL;
        tail = NULL;
     }

    void push_front(int val){
        Node* newNode = new Node(val); //dynamic
        /* Node* newNode(val); //static (dont use) */

        if(head == NULL){ //if empty LL
            head = tail = newNode;
        }
        else{ //if not empty
            newNode->next = head; //newNode.next
            head = newNode;
        }
     }

     void printList(){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
     }

     int getSize(){ //To calculate  size of LL.
        int sz = 0;
        Node* temp = head;

        while(temp != NULL){
            temp = temp->next;
            sz++;
        }
        return sz;
     }

     void removeNth(int n){
        int size = getSize();
        Node* prev = head;

        for (int i = 1; i < (size-n); i++)
        {
            prev = prev -> next;
        }

        Node* toDel = prev -> next;
        cout<<"going to delete : "<<toDel->data << endl;
        prev -> next = prev -> next -> next;
     }
};



int main() {
    List ll;
    
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.printList(); //before deletion
    ll.removeNth(2);
    ll.printList(); //after deletion
    
    return 0;
}
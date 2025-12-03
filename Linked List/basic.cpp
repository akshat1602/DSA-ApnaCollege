#include <iostream>
#include <vector>
#include <list>
using namespace std;

//----Basic Structure of LL----

class Node{ //For creating a new node.
public : //always keep members public in node creation
    int data;
    Node* next;

     Node(int val){
        data = val;
        next = NULL;
     }
};

class List{ //For creating a new List.
    Node* head; // points to 1st node.
    Node* tail; // points to last node.

public : 
    List()
    {
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

    void push_back(int val){
        Node* newNode = new Node(val); //dynamic
        /* Node* newNode(val); //static (dont use) */

        if(head == NULL){ //if empty LL
            head = tail = newNode;
        }
        else{ //if not empty
            tail->next = newNode; //newNode.next
            tail = newNode;
        }
     }

     void printList(){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
     }

     void insert(int val, int pos){
        Node* newNode = new Node(val);

        Node* temp = head;
        for (int i = 0; i < pos-1; i++){
            if(temp == NULL){
                cout<<"Invalid Postion!!\n";
                return; //wapis bahar aajao.
            }
            temp = temp->next;
        }
        
        //temp is now at pos-1 i.e. previous/left one.
        newNode->next = temp->next;
        temp->next = newNode;
        
     }
};

int main() {
    List ll; //calling constructor thats why.
    
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1); 
    ll.push_back(4);
    ll.push_back(5);
    ll.printList(); // 1->2->3->4->5->NULL.

    ll.insert(100,2);
    ll.printList();

    return 0;
}
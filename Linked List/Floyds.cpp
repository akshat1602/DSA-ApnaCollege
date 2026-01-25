#include <iostream>
#include <vector>
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
public:
    Node* head;
    Node* tail;
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

    void pop_front(){
        if(head == NULL){ //corner case
            cout<<"LL is empty \n";
            return;
        }

        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
     }
};

void printList(Node* head){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
}

bool isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next; //+1
        fast = fast->next->next; //+2

        if(slow == fast) {
            cout<<"cycle exits \n";
            return true;
        }
    }
    cout<<"cycle doesn't exits \n";
    return false;
}

int main() {
    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1); 
    
    //1->2->3->4->5->1
    ll.tail->next = ll.head; //for cycle.

    isCycle(ll.head);

    return 0;
}
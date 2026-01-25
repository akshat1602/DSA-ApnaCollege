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
};
     
void printList(Node* head){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
}

Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev != NULL){
        prev->next = NULL; //split at middle
    }

    return slow; //righthead
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev; //it is the head of reversed LL.
}

Node* zigZagLL(Node* head){
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    //alternate merging -> 1st head = head, 2nd head = rightHead.
    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = right;

    while(left != NULL && right != NULL){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;

        tail = right;

        left = nextLeft;
        right = nextRight;
    }
    
    if(right != NULL){
        tail->next = right;
    }

    return head;
}

int main() {
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    printList(ll.head);

    ll.head = zigZagLL(ll.head);
    printList(ll.head);

    return 0;
}
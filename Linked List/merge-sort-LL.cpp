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

Node* merge(Node* left, Node* right){
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i->next;
        }
        else{
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while(i != NULL){
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL){
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

Node* mergeSort(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head); //left head
    Node* right = mergeSort(rightHead); //right head

    return merge(left, right); //head of sorted LL.
}

int main(){
    List ll;

    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);
    printList(ll.head);

    ll.head = mergeSort(ll.head);
    printList(ll.head);
}
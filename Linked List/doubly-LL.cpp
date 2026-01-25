#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        prev = next = NULL;
    }
};

class DoublyList{
    public:
    Node* head;
    Node* tail;

    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode; 
        }
    }

    void pop_front(){
        Node* temp = head;
        head = head -> next;

        if(head != NULL){ //if only single element is not present.
            head -> prev = NULL; //prev connection broken
        }
        temp -> next = NULL; //next connection broken
        delete temp;
    }

    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }

    //HW : Apply push_back() and pop_back() functions.
};

int main() {
    DoublyList dll;
    dll.push_front(5);
    dll.push_front(4);
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.printList();

    dll.pop_front();
    dll.printList();

    return 0;
}
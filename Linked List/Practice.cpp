#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    ~List()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    void push_front(int val){
        Node *newNode = new Node(val);

        if (head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    //Insert and deletion
    void insert(int val, int pos){
        Node* newNode = new Node(val);

        Node* temp = head;
        for(int i = 0; i<pos-1; i++){
            if(temp == NULL){
                cout<<"Invalid Position!!\n";
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front(){
        if(head == NULL){
            cout<<"LL is empty \n";
            return;
        }

        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;
        
        while(temp->next->next != NULL){ // eg : 1->2->NULL
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }


    //SEARCHING
    //Iterative
    int searchInt(int key){
        Node* temp = head;
        int idx = 0;

        while(temp != NULL){
            if(temp->data == key) return idx;

            temp = temp->next;
            idx++;
        }

        return -1;
    }

    //Recursive
    int helper(Node* temp, int key){
        if(temp == NULL) return -1;

        if(temp->data == key) return 0;

        int idx = helper(temp->next, key);

        if(idx == -1) return -1;

        return idx+1;
    }
    int searchRec(int key){
        return helper(head, key);
    }

    
    //Reversal
    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        tail = head;

        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

void traverseList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data;
        if (head->next != nullptr)
            cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    List ll;

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    traverseList(head);

    return 0;
}
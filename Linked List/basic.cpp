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

     ~Node(){
         /* cout<<"~Node " << data << endl; */

        if(next != NULL){
            delete next;
            next = NULL;
        }
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

    ~List(){  //destructor to free memory

        /* cout<<"~List\n"; */

        if(head != NULL){
            delete head;
            head = NULL;
        }
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

     void pop_back(){
        Node* temp = head;

        while(temp->next->next != NULL){
            temp = temp->next; //moving forward
        }

        temp->next = NULL; //temp = tail's previous element
        delete tail;
        tail = temp;
     }
     
     //Iterative search
     int searchItr(int key){
        Node* temp = head;
        int idx = 0; //index variable.

        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }

            temp = temp->next;
            idx++;
        }

        return -1; //element not present
     }
     
     //Recursive Search
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

     //Reverse LL
     void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        tail = head;

        while(curr != NULL){
            Node* next = curr -> next;
            curr -> next = prev;

            //updation for next iteration
            prev = curr;
            curr = next;
        }
        head = prev;
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

    ll.reverse();
    ll.printList(); // 5->4->3->2->1->NULL.

    ll.insert(100,2);
    ll.printList();

    cout<<ll.searchItr(2)<<endl;

    ll.pop_front();
    ll.printList();

    ll.pop_back();
    ll.printList();

    cout<<ll.searchItr(2)<<endl;

    return 0;
}
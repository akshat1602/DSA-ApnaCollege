#include <iostream>
#include <vector>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){ //O(logn)
    if(root == NULL){
        root = new Node(val); //inserting the ith value.
        return root;
    }

    if(val < root->data){ //left subtree.
        root->left = insert(root->left, val);
    }
    else{ //right subtree.
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(int arr[], int n){ //O(nlogn) ~ approx
    Node* root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    return root;
}

void printInRange(Node* root, int st, int end){
    if(root == NULL){
        return;
    }

    if(st <= root->data && root->data <= end){ //case-1
        //inorder printing -> sorted
        printInRange(root->left, st, end);
        cout<<root->data<<" ";
        printInRange(root->right, st, end);
    }
    else if(root->data < st){ //case-2
        printInRange(root->right, st, end);
    }
    else{ //case-3
        printInRange(root->left, st, end);
    }
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9);
    int st = 5, end = 12;

    inorder(root); //sorted aaega
    cout<<endl;

    printInRange(root, st, end);
    return 0;
}
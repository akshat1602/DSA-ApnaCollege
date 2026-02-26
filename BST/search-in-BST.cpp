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

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool search(Node* root, int key){ //O(height), avg cases ~ O(logn)
    if(root == NULL){
        return false;
    }

    if(root->data == key){ //key found
        return true;
    }
    else if(root->data > key){ //left subtree
        return search(root->left, key);
    }
    else{ //right subtree
        return search(root->right, key);
    }
}

int main() {
    int arr[6] = {5, 1, 3, 4, 2, 7};
    Node* root = buildBST(arr, 6);
    int key = 8;

    inorder(root); //sorted aaega
    cout<<endl;
    cout<<search(root, key)<<endl;
    return 0;
}
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

Node* getInorderSuccessor(Node* root){
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root; //IS
}

Node* delNode(Node* root, int val){
    if(root == NULL){
        return NULL;
    }

    if(val < root->data){ //left subtree
        root->left = delNode(root->left, val);
    }
    else if(val > root->data){ //right subtree
        root->right = delNode(root->right, val);
    }
    else{
        //root == val
        //case 0 : With 0 child.
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL; //connecting the null node
        }

        //case 1 : With 1 child.
        if(root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left;
        }

        //case 2 : With 2 children.
        //Find Inorder successor.
        Node* IS =  getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data); //case 0 , case 1.
    }

    return  root;
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9);
    
    inorder(root);
    delNode(root, 5);
    cout<<endl;
    cout<<"After Deletion : ";
    inorder(root);

    return 0;
}
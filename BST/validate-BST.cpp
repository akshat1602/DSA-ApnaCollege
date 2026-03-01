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

bool validateHelper(Node* root, Node* min, Node* max){
   if(root == NULL){
    return true;
   }

   if(min != NULL && root->data < min->data){ //chote se bhi chota nhi hona chaiye
    return false;
   }

   if(max != NULL && root->data > max->data){ //bade se bhi bada nhi hona chaiye
    return false;
   }

   return validateHelper(root->left, min, root) &&
          validateHelper(root->right, root, max);
}

bool validateBST(Node* root){
    return validateHelper(root, NULL, NULL);
}

int main() {
   int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9);

    root->data = 15;

    cout<<validateBST(root)<<endl;
    return 0;
}
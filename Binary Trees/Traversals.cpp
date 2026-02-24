//Using recursion

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left; //points left child
    Node* right; //points right child

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector <int> nodes){ //TC : O(n)
    idx++; //come in valid range.
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode -> left = buildTree(nodes); //left subtree
    currNode -> right = buildTree(nodes); //right subtree

    return currNode;
}

//PREORDER
void preorder(Node* root){ //TC : O(n)
    if(root == NULL){
        return;
    }

    cout<<root->data<<" "; //root
    preorder(root->left); //left
    preorder(root->right); //right
}

//INORDER
void inorder(Node* root){ //TC : O(n)
    if(root == NULL){
        return;
    }
    
    inorder(root->left); //left
    cout<<root->data<<" "; //root
    inorder(root->right); //right
}

//POSTORDER
void postorder(Node* root){ //TC : O(n)
    if(root == NULL){
        return;
    }
    
    postorder(root->left); //left
    postorder(root->right); //right
    cout<<root->data<<" "; //root
}

int main() {
    vector <int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes); //1

    /* cout<<"Root = "<<root->data<<endl; */
    
    //pre
    preorder(root);
    cout<<endl;
    
    //in
    inorder(root);
    cout<<endl;
    
    //post
    postorder(root);
    cout<<endl;
    return 0;
}
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

int kthAncestor(Node* root, int node, int K){
    //yeh function distance return karega ancestor se node tk.
    if(root == NULL){
        return -1; //valid node not present
    }

    if(root->data == node){
        return 0; //same node hai tbhi 0 value
    }

    int leftDis = kthAncestor(root->left, node, K); //for left
    int rightDis = kthAncestor(root->right, node, K); //for right

    if(leftDis == -1 && rightDis == -1){
        return -1;
    }

    int validVal = leftDis == -1 ? rightDis : leftDis;

    if(validVal + 1 == K){
        cout<<"Kth Ancestor : "<<root->data<<endl; //yeh accestor print karega
    }

    return validVal + 1;//+1 kyuki ek level upar hoga
}

int main() {
    vector <int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes); //1

    int node = 5, K = 1;
    kthAncestor(root, node, K);

    return 0;
}
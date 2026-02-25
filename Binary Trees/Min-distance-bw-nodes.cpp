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

Node* LCA2(Node* root, int n1, int n2){ //TC : O(n), SC : O(1)
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2); //Left subtree
    Node* rightLCA = LCA2(root->right, n1, n2); //right subtree

    if(leftLCA != NULL && rightLCA != NULL){ //when both L and R are valid.
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA; //remaining 3 cases covered
}

int dist(Node* root, int n){
    if(root == NULL){
        return -1; //means no root exist
    }

    if(root->data == n){
        return 0;
    }

    int leftDis = dist(root->left, n);// to find left distance
    if(leftDis != -1){
        return leftDis + 1; //adding the self node also tabhi plus 1.
    }

    int rightDis = dist(root->right, n);// to find right distance
    if(rightDis != -1){
        return rightDis + 1; //adding the self node also tabhi plus 1.
    }

    return -1;
}

int minDis(Node* root, int n1, int n2){ //TC : O(n)
    Node* lca = LCA2(root, n1, n2);

    int dist1 = dist(lca, n1); //for n1 side distance
    int dist2 = dist(lca, n2); //for n2 side distance

    return dist1 + dist2;
}

int main() {
    vector <int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes); //1

    int n1 = 4, n2 = 6;
    
    cout<<"Minimum distance : "<<minDis(root, n1, n2); 

    return 0;
}
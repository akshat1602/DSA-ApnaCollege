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

bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){ //same structure with nothing
        return true;
    }

    else if(root1 == NULL || root2 == NULL){ //on any side if different
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

   return isIdentical(root1->left, root2->left)
    && isIdentical(root1->right, root2->right);
}

bool isSubTree(Node* root, Node* subRoot){
    if(root == NULL && subRoot == NULL){
        return true;
    }
    else if(root == NULL || subRoot == NULL){
        return false;
    }

    if(root->data == subRoot->data){
       if (isIdentical(root, subRoot)){
            return true;
       } //false mein return mat karo then wapis se check karo ki kahi aur toh nhi hai subtree wala structure.
    }

    int isLeftSubtree = isSubTree(root->left, subRoot);

    if(!isLeftSubtree){
        return isSubTree(root->right, subRoot);
    }

    return true;
}

int main() {
    vector <int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes); //1

    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    cout<<isSubTree(root, subRoot)<<endl; //1 -> true, 0 -> false
    return 0;
}
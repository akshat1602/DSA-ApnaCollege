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

//IMPORTANT INDIVIDUAL LOGIC TOO.
bool rootToNodePath(Node* root, int n, vector <int> &path){ //TC : O(n)
    if(root == NULL){
        return false;
    }

    path.push_back(root -> data); //base root toh add kardo
    if(root -> data == n){
        return true;
    }

    int isLeft = rootToNodePath(root->left, n, path); //left subtree
    int isRight = rootToNodePath(root->right, n, path); //right subtree

    if(isLeft || isRight){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2){ //TC : O(n)
    vector <int> path1; //for n1
    vector <int> path2; //for n2

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for (int i = 0, j = 0;  i < path1.size() && j < path2.size(); i++, j++)
    {
        if(path1[i] != path2[j]){ //jab pehla uncommon pair mile toh it means lca mein answer hai
            return lca;
        }
        lca = path1[i]; //can be path2[j] also because both are same.
    }
    
    return lca;
}

//***APPROACH - 2***
//no additional path vectors used
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

int main() {
    vector <int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes); //1

    int n1 = 4, n2 = 5;
    cout<<"LCA : "<<LCA(root, n1, n2)<<endl; //yahan value bheji
    cout<<"LCA with constant space: "<<LCA2(root, n1, n2)->data<<endl; //yahan root bheja

    return 0;
}
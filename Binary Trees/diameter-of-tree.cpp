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

int height(Node* root){ //TC : O(n)
    if(root == NULL){ //when empty tree
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int currHeight = max(leftHeight, rightHeight) + 1;

    return currHeight;
}


//APPROACH - 1
int diam1(Node* root){ //TC : O(n^2)
    
    if(root == NULL){
        return 0;
    }

    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}


//APPROACH - 2
pair <int, int> diam2(Node* root){ //TC : O(n)
    
    if(root == NULL){
        return make_pair(0, 0); //diameter and height both 0 here.
    }
    
    //(diameter, height)
    pair <int, int> leftInfo = diam2(root->left); //LeftDia, LeftHeight
    pair <int, int> rightInfo = diam2(root->right); //rightDia, rightHeight
    
    //for diameter.
    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam ,max(leftInfo.first, rightInfo.first));
    
    int finalHeight = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHeight);
}

int main() {
    vector <int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes); //1
    
    //By app.1
    cout<<"Height of Tree : "<<height(root)<<endl;
    cout<<"Diameter of Tree : "<<diam1(root)<<endl;
    
    cout<<"-------------------------"<<endl;
    //By app.2
    cout<<"Height of Tree : "<<height(root)<<endl;
    cout<<"Diameter of Tree : "<<diam2(root).first<<endl;

    return 0;
}
//Using recursion

#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

void topView(Node* root){
    queue <pair <Node*, int>> q; //(node, HD)
    map <int, int> m; //(HD, node->data)

    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair <Node*, int> curr = q.front(); //intial pair ko lene ke liye
        q.pop();

        Node* currNode = curr.first; //stores node
        int currHD = curr.second; //stores HD

        if(m.count(currHD) == 0){ //HD -> doesnt exist, so add in map.
            m[currHD] = currNode->data; 
        }

        if(currNode->left != NULL){ //For left node
            pair <Node*, int> left = make_pair(currNode->left, currHD - 1);
            q.push(left);
        }

        if(currNode->right != NULL){ //For right node
            pair <Node*, int> right = make_pair(currNode->right, currHD + 1);
            q.push(right);
        }
    }
    
    cout<<"Top View Of Tree : ";
    for (auto it : m)
    {
        cout<<it.second<<" ";
    }
    
}

//***TRY BOTTOM VIEW H.W.*** 

int main() {
    vector <int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes); //1

    topView(root);

    return 0;
}
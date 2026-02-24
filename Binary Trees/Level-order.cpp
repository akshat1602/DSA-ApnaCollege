// Using recursion

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;  // points left child
    Node *right; // points right child

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> nodes)
{ // TC : O(n)
    idx++; // come in valid range.
    if (nodes[idx] == -1)
    {
        return NULL;
    }

    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);  // left subtree
    currNode->right = buildTree(nodes); // right subtree

    return currNode;
}

void levelOrder(Node *root)
{ // TC : O(n), SC : O(n)
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();

        cout << currNode->data << " ";

        if (currNode->left != NULL)
        {
            q.push(currNode->left);
        }
        if (currNode->right != NULL)
        {
            q.push(currNode->right);
        }
    }
    cout << endl;
}

void levelOrderVariation(Node *root)
{ // TC : O(n), SC : O(n)
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();

        if (currNode == NULL)
        {
            cout << endl; // main logic to change line
            if (q.empty())
            { // to avoid infinite loop
                break;
            }
            q.push(NULL);
        }

        else
        {
            cout << currNode->data << " ";

            if (currNode->left != NULL)
            {
                q.push(currNode->left);
            }
            if (currNode->right != NULL)
            {
                q.push(currNode->right);
            }
        }
    }
    cout << endl;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes); // 1

    levelOrder(root);
    cout<<"--------------"<<endl;
    levelOrderVariation(root);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    cout << "Enter value : ";
    int val;
    cin >> val;

    if (val == -1)
        return NULL;

    Node *root = new Node(val);
    cout << "Left Node of " << val << " - ";
    root->left = buildTree();
    cout << "Right Node of " << val << " - ";
    root->right = buildTree();
    return root;
}

Node *buildTreeFromLevelOrder()
{
    cout << "Enter root node value : ";
    int value;
    cin >> value;
    Node *root = new Node(value);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftVal;
        cout << "Enter left node value for " << temp->data << " : ";
        cin >> leftVal;
        if (leftVal != -1)
        {
            temp->left = new Node(leftVal);
            q.push(temp->left);
        }

        int rightVal;
        cout << "Enter right node value for " << temp->data << " : ";
        cin >> rightVal;
        if (rightVal != -1)
        {
            temp->right = new Node(rightVal);
            q.push(temp->right);
        }
    }
    return root;
}

void inOrder(Node *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{

    Node *root = NULL;

    // root = buildTree();
    root = buildTreeFromLevelOrder();
    inOrder(root);
    return 0;
}
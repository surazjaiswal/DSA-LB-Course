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

void inOrder(Node *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int getheight(Node *root)
{
    if (!root)
        return 0;

    int leftHeight = getheight(root->left);
    int rightHeight = getheight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main()
{

    Node *root = NULL;

    root = buildTree();
    inOrder(root);
    return 0;
}
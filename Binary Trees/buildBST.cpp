#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;
    Node(int val)
    {
        this->val = val;
        left == NULL;
        right = NULL;
    }
};

int getPredecessor(Node *root, int key);
int getSucessor(Node *root, int key);

Node *addNode(Node *root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
        return root;
    }
    else if (x < root->val)
    {
        cout << "left of " << root->val << endl;
        root->left = addNode(root->left, x);
    }
    else
    {
        cout << "right of " << root->val << endl;
        root->right = addNode(root->right, x);
    }
    return root;
}

void takeInput(Node *&root)
{
    int x;
    cin >> x;

    while (x != -1)
    {
        root = addNode(root, x);
        cout << "added new node" << endl;
        cin >> x;
    }
}

Node *deleteFromBST(Node *root, int key)
{
    // base case key not found
    if (!root)
        return NULL;
    if (root->val == key)
    {
        // key found, it will have total of 5 cases
        //  0 child
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        //  1 child
        //  for left child
        if (root->left && !root->right)
        {
            Node *temp = root->left;
            delete root->left;
            return temp;
        }
        // for right child
        if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root->right;
            return temp;
        }
        //  2 child
        if (root->left && root->right)
        {
            // there are 2 options to delete this node
            // by replacing it with inorder predecessor or inorder successor
            // replacing it with its inorder predecessor, which is max value in left subtree

            // int pre = getPredecessor(root->left, root->val);
            // root->val = pre;
            // root->left = deleteFromBST(root->left, root->val); // this rec will then go to delete the pre form the left sub tree, the same will be followed later too.

            // we can also replace it inorder sucessor node
            int suc = getSucessor(root->right, key);
            root->val = suc;
            root->right = deleteFromBST(root->right, root->val);

            // we can use either of the two
        }
    }
}

int getSucessor(Node *root, int key)
{
    int suc = -1;

    while (root)
    {
        if (root->val > key)
        {
            // this might be the successor, mark it as suc and then try to find a value smaller than current suc but just greater than key
            suc = root->val;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return suc;
}

int getPredecessor(Node *root, int key)
{
    int pre = -1;
    while (root)
    {
        if (root->val < key)
        {
            // this might be pre, so save this as pre, and then try to serach for a larger value just smaller than key
            pre = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return pre;
}

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{

    Node *root = NULL;
    takeInput(root);
    inorder(root);

    return 0;
}
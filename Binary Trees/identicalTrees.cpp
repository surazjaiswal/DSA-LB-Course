#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *buildTree()
{
    cout << "Enter value : ";
    int val;
    cin >> val;

    if (val == -1)
        return NULL;

    TreeNode *root = new TreeNode(val);
    cout << "Left TreeNode of " << val << " - ";
    root->left = buildTree();
    cout << "Right TreeNode of " << val << " - ";
    root->right = buildTree();
    return root;
}

void inOrder(TreeNode *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

bool checkIdentical(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return true;

    if ((root1 && !root2) || (!root1 && root2))
        return false;

    bool leftChk = checkIdentical(root1->left, root2->left);
    bool rightChk = checkIdentical(root1->right, root2->right);

    if (leftChk && rightChk && root1->data == root2->data)
        return true;
    else
        return false;
}

int main()
{

    TreeNode *root = NULL;

    root = buildTree();
    inOrder(root);
    return 0;
}

// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int val)
    {
        this->val = val;
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
    cout << root->val << " ";
    inOrder(root->right);
}

class Solution
{
public:
    TreeNode *getLCA(TreeNode *root, int a, int b)
    {
        if (!root)
            return root;

        if (root->val == a || root->val == b)
        {
            return root;
        }

        TreeNode *leftLCA = getLCA(root->left, a, b);
        TreeNode *rightLCA = getLCA(root->right, a, b);

        if (leftLCA && rightLCA)
            return root;
        else if (leftLCA && !rightLCA)
            return leftLCA;
        else if (!leftLCA && rightLCA)
            return rightLCA;
        else
            return NULL;
    }
};

int main()
{

    TreeNode *root = NULL;

    root = buildTree();
    inOrder(root);
    return 0;
}

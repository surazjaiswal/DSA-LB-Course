//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/

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

// boundry traversal -> traverseLeft + traverseLeaf + traverseRight_reverse

void boundryTraverse(TreeNode *root)
{
    if (!root)
        return;

    vector<int> ans;
    ans.push_back(root->val);
    traverseLeft(root->left, ans);
    traverseLeaf(root, ans);
    traverseRight(root->right, ans);
}

void traverseLeft(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        return;

    ans.push_back(root->val);
    traverseLeft(root->left, ans);
    traverseLeft(root->right, ans);
}

void traverseLeaf(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        ans.push_back(root->val);

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        return;

    traverseRight(root->right, ans);
    traverseRight(root->left, ans);
    ans.push_back(root->val);
}

int main()
{

    TreeNode *root = NULL;

    root = buildTree();
    inOrder(root);
    return 0;
}

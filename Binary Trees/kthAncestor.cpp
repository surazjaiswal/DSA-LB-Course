// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1/

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
    int kthAncestor(TreeNode *root, int k, int node)
    {
        TreeNode *ans;
        ans = solve(root, k, node);
        if (ans == NULL || ans->val == node)
            return -1;
        return ans->val;
    }

    TreeNode *solve(TreeNode *root, int &k, int node)
    {
        if (!root)
            return NULL;

        if (root->val == node)
            return root;

        TreeNode *leftAns = solve(root->left, k, node);
        TreeNode *rightAns = solve(root->right, k, node);

        // if (leftAns || rightAns)
        // {
        //     k--;
        //     if (k <= 0)
        //         return root;
        //     return (leftAns) ? leftAns : rightAns;
        // }
        if (leftAns && !rightAns)
        {
            k--;
            if (k <= 0)
            {
                k = INT_MAX;
                return root;
            }
            return leftAns;
        }

        if (!leftAns && rightAns)
        {
            k--;
            if (k <= 0)
            {
                k = INT_MAX;
                return root;
            }
            return rightAns;
        }
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

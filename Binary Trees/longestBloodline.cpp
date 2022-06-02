// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

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
    int getLongestPathSum(TreeNode *root)
    {
        if (!root)
            return 0;

        int sum = 0;
        int len = 0;

        int maxSum = sum, maxLen = len;

        traverse(root, sum, len, maxSum, maxLen);

        return maxSum;
    }

    void traverse(TreeNode *root, int sum, int len, int &maxSum, int &maxLen)
    {
        if (!root)
            return;

        sum += root->val;

        if (!root->left && !root->right)
        {
            if (len >= maxLen)
            {
                maxSum = max(maxSum, sum);
                maxLen = len;
            }
        }

        traverse(root->left, sum, len + 1, maxSum, maxLen);
        traverse(root->right, sum, len + 1, maxSum, maxLen);
    }
};

int main()
{

    TreeNode *root = NULL;

    root = buildTree();
    inOrder(root);
    return 0;
}

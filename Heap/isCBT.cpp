// https://leetcode.com/problems/check-completeness-of-a-binary-tree/

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
    }
};

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isCBT(TreeNode *root, int idx, int size)
    {
        if (!root)
            return true;

        if (idx >= size)
            return false;

        bool left = isCBT(root->left, idx * 2 + 1, size);
        bool right = isCBT(root->right, idx * 2 + 2, size);

        return (left && right);
    }

    bool isCompleteTree(TreeNode *root)
    {
        int size = countNodes(root);
        return isCBT(root, 0, size);
    }
};

int main()
{

    return 0;
}
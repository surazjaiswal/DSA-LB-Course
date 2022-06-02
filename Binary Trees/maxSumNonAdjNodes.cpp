// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/

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
    int getMaxSum(TreeNode *root)
    {
        if (!root)
            return 0;
        pair<int, int> ans = solve(root); // <max_including, max_excluding>

        return max(ans.first, ans.second);
    }

    pair<int, int> solve(TreeNode *root)
    {
        if (!root)
            return {0, 0};

        pair<int, int> leftAns = solve(root->left);
        pair<int, int> rightAns = solve(root->right);

        int leftIn = leftAns.first;
        int leftEx = leftAns.second;

        int rightIn = rightAns.first;
        int rightEx = rightAns.second;

        int currIn = root->val + leftEx + rightEx;
        int currEx = max(leftIn, leftEx) + max(rightIn, rightEx); // ******* //

        return {currIn, currEx};
    }
};

int main()
{

    TreeNode *root = NULL;

    root = buildTree();
    inOrder(root);
    return 0;
}

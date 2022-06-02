// https://practice.geeksforgeeks.org/problems/k-sum-paths/1/

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
    int getKSumPath(TreeNode *root, int k)
    {
        if (!root)
            return 0;

        int count = 0;
        vector<int> path;
        solve(root, count, path, k);

        return count;
    }

    void solve(TreeNode *root, int &count, vector<int> &path, int k)
    {
        if (!root)
            return;

        path.push_back(root->val);

        solve(root->left, count, path, k);
        solve(root->right, count, path, k);

        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == k)
                count++;
        }

        path.pop_back();
    }
};

int main()
{

    TreeNode *root = NULL;

    root = buildTree();
    inOrder(root);
    return 0;
}

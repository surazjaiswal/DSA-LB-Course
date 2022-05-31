// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1/

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
    vector<int> bottomView(TreeNode *root)
    {
        if (!root)
            return {};

        map<int, int> mp;               // dist, value
        queue<pair<TreeNode *, int>> q; // node,dist

        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            TreeNode *node = it.first;
            int dist = it.second;
            q.pop();

            mp[dist] = node->val;

            if (node->left)
                q.push({node->left, dist - 1});

            if (node->right)
                q.push({node->right, dist + 1});
        }
        vector<int> ans;
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main()
{

    TreeNode *root = NULL;

    root = buildTree();
    inOrder(root);
    return 0;
}

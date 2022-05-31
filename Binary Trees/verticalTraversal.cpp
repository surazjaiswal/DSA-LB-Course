// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        map<int, map<int, vector<int>>> mp;        // mp[dist,[level,data]]
        queue<pair<TreeNode *, pair<int, int>>> q; // <node,<dist,level>>

        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            TreeNode *node = it.first;
            int dist = it.second.first;
            int level = it.second.second;

            mp[dist][level].push_back(node->val);

            if (node->left)
                q.push({node->left, {dist - 1, level + 1}});

            if (node->right)
                q.push({node->right, {dist + 1, level + 1}});
        }

        vector<vector<int>> ans;
        for (auto it : mp)
        {
            for (auto jt : it.second)
            {
                ans.push_back(jt.second);
            }
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

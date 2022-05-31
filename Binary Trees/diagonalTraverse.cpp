// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1/#
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

vector<int> diagonalTraverse(TreeNode *root)
{
    if (!root)
        return {};

    queue<TreeNode *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        while (node)
        {
            if (node->left)
                q.push(node->left);

            ans.push_back(node->val);
            node = node->right;
        }
    }
    return ans;
}

// does not pass hidden test cases
class Solution
{
public:
    vector<vector<int>> diagonalTraverse(TreeNode *root)
    {
        if (!root)
            return {};

        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;

        int minDst = INT_MAX, maxLvl = 0;

        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            TreeNode *node = it.first;
            int dist = it.second.first;
            int level = it.second.second;

            minDst = min(minDst, dist);
            maxLvl = max(maxLvl, level);

            mp[dist][level].push_back(node->val);

            if (node->left)
                q.push({node->left, {dist - 1, level + 1}});

            if (node->right)
                q.push({node->right, {dist + 1, level + 1}});
        }

        vector<vector<int>> ans;
        for (int g = 0; g < maxLvl; g++)
        {
            vector<int> vt;
            for (int i = -g, j = g; j <= maxLvl; i++, j++)
            {
                if (mp[i].find(j) != mp[i].end())
                {
                    for (int k : mp[i][j])
                    {
                        vt.push_back(k);
                    }
                }
            }
            ans.push_back(vt);
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

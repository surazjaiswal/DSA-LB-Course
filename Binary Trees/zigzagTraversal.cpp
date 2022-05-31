// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1/#
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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         if (!root)
            return {};

        vector<vector<int>> ans;

        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> vt;
            while (sz--)
            {
                TreeNode *node = q.front();
                q.pop();

                vt.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (level & 1)
                reverse(vt.begin(), vt.end());
            ans.push_back(vt);
            
            level++;
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

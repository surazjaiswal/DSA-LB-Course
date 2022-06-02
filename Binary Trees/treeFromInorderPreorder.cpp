// https://practice.geeksforgeeks.org/problems/construct-tree-1/1/

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

void postOrder(TreeNode *root)
{
    if (!root)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

class Solution
{
public:
    unordered_map<int, int> mp;
    TreeNode *createTree(vector<int> inorder, vector<int> preorder)
    {

        int preIdx = 0;         // preorder index
        int n = inorder.size(); // inorder start

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        TreeNode *root = solve(inorder, preorder, 0, 0, n, n); // solve(inorder,preorder,preIdx,inStart,inEnd,n)

        return root;
    }

    TreeNode *solve(vector<int> &inorder, vector<int> &preorder, int preIdx, int inStart, int inEnd, int n)
    {
        if (preIdx >= n || inStart > inEnd)
            return NULL;

        int num = preorder[preIdx];
        int pos = mp[num];

        TreeNode *node = new TreeNode(num);
        node->left = solve(inorder, preorder, preIdx + 1, inStart, pos - 1, n);
        node->right = solve(inorder, preorder, preIdx + 1, pos + 1, inEnd, n);

        return node;
    }
};

int main()
{

    TreeNode *root = NULL;

    root = buildTree();
    postOrder(root);
    return 0;
}

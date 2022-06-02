// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1/

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
    TreeNode *createTree(vector<int> inorder, vector<int> postorder)
    {

        int postIdx = 0;         // postorder index
        int n = inorder.size(); // inorder start

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        TreeNode *root = solve(inorder, postorder, 0, 0, n, n); // solve(inorder,postorder,postIdx,inStart,inEnd,n)

        return root;
    }

    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int postIdx, int inStart, int inEnd, int n)
    {
        if (postIdx < 0 || inStart > inEnd)
            return NULL;

        int num = postorder[postIdx];
        int pos = mp[num];

        TreeNode *node = new TreeNode(num);
        // in this case right part will be build first then left part, complimentary to postorder
        node->right = solve(inorder, postorder, postIdx + 1, pos + 1, inEnd, n);
        node->left = solve(inorder, postorder, postIdx + 1, inStart, pos - 1, n);

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

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root;
        int i = 0;
        root = buildBST(root, i, INT_MIN, INT_MAX, preorder);
        return root;
    }

    TreeNode *buildBST(TreeNode *root, int &i, int min, int max, vector<int> &preorder)
    {
        // base case
        // if elements exhausted in preorder
        if (i >= preorder.size())
            return NULL;
        // if current element is not in the required range
        if (preorder[i] < min || preorder[i] > max)
            return NULL;
        // else ceate new node for current element
        root = new TreeNode(preorder[i]);
        i++;

        // recursive build for left and right parts
        // since preorder (root, left, right)

        root->left = buildBST(root->left, i, min, root->val, preorder);
        root->right = buildBST(root->right, i, root->val, max, preorder);

        return root;
    }
};

int main()
{

    return 0;
}
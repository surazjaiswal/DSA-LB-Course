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
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> nums;
        traverse(root, nums);
        TreeNode *newRoot;
        newRoot = buildBST(0, nums.size() - 1, nums);
        return newRoot;
    }

    TreeNode *buildBST(int i, int j, vector<int> &nums)
    {
        if (i > j)
            return NULL;
        int mid = (i + j) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = buildBST(i, mid - 1, nums);
        node->right = buildBST(mid + 1, j, nums);
        return node;
    }

    void traverse(TreeNode *root, vector<int> &nums)
    {
        if (!root)
            return;

        traverse(root->left, nums);
        nums.push_back(root->val);
        traverse(root->right, nums);
    }
};

int main()
{
    return 0;
}
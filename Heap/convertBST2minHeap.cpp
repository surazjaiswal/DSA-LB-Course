// https://www.geeksforgeeks.org/convert-bst-min-heap/

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
    }
};

// the important point is that it is already complete binary tree is given
// and the structure of tree will remain same for the min heap also

// step 1 get the inorder
void inorder(TreeNode *root, vector<int> &nums)
{
    if (!root)
        return;

    inorder(root->left);
    nums.push_back(root->val);
    inorder(root->right);
}

// step 2 : fill the inorder values in given tree in preorder manner
void preorder(TreeNode *root, vector<int> &nums, int &idx)
{
    if (!root)
        return;

    // fill root first
    root->data = nums[i++];
    preorder(root->left, nums, idx);
    preorder(root->right, nums, i);
}

TreeNode *convert(TreeNode *root)
{
    vector<int> nums;
    inorder(root, nums);

    // for min heap : N < L && N < R
    // also we left subtree values should be less than right subtree values
    // L < R

    // therefore => N < L < R ----> which is preorder traversal
    // now we fill the values of inorder in the given tree in preorder tarversal manner
    preorder(root, nums, 0);
    return root;
}

int main()
{

    return 0;
}
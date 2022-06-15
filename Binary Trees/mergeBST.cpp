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

// Approach 1
// in this apporach we will simply flatten both the BST's to vector and then merge them (like merge two sorted arrays)
// and then we create a new BST form the new merged array
// this merged array is sorted and hence it will be the inorder of required BST
// using this inorder we create new BST
class Solution1
{
public:
    TreeNode *mergeBST(TreeNode *root1, TreeNode *root2)
    {
        vector<int> nums1, nums2, nums;
        traverse(root1, nums1);
        traverse(root2, nums2);
        mergeArr(nums, nums1, nums2);
        TreeNode *root;
        root = buildBST(0, nums.size() - 1, nums);

        return root;
    }

    void traverse(TreeNode *root, vector<int> &nums)
    {
        if (!root)
            return;
        traverse(root->left, nums);
        nums.push_back(root->val);
        traverse(root->right, nums);
    }

    void mergeArr(vector<int> &nums, vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                nums.push_back(nums1[i++]);
            }
            else
            {
                nums.push_back(nums2[j++]);
            }
        }

        while (i < nums1.size())
        {
            nums.push_back(nums1[i++]);
        }

        while (j < nums2.size())
        {
            nums.push_back(nums2[j++]);
        }
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
};

int main()
{
    return 0;
}
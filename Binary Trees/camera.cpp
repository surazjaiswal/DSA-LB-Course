#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    int minCameraCover(TreeNode *root)
    {
        /**
         *  1 -> unwatched
         *  2 -> watched but no camera
         *  3 -> watched with camera
         */

        int ans = camera(root);
        // check if root is unwatched
        if (root->val == 1)
        {
            ans++;
        }

        return ans;
    }

    int camera(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            // leaf node, needs to be watched by its parent
            root->val = 1; // marking it as unwatched
            return 0;      // zero camera installed
        }

        int res = 0, left = 2, right = 2;
        if (root->left)
        {
            res += camera(root->left); // number of cam installed in left
            left = root->left->val;    // get the status of left child
        }

        if (root->right)
        {
            res += camera(root->right); // number of camera installed in right
            right = root->right->val;   // status of right child
        }

        // if left or right child are unwatched
        if (left == 1 || right == 1)
        {
            root->val = 3;  // then install camera at this parent position
            return 1 + res; // returning number of cams installed
        }

        // current node is watched by cameras installed to its left or right child
        if (left == 3 || right == 3)
        {
            root->val = 2; // marking it watched
            return res;    // returning number of cams installed
        }

        // current node is unwatched, and now it will be watched by its parent
        root->val = 1;
        return res;
    }
};

int main()
{
    return 0;
}
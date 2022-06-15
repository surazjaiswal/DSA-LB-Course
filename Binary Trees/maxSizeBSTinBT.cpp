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

// brute force apporach we tend to check for valid BST for every node in given tree
// which will lead to O(N^2) time complexity

class values
{
public:
    int size;   // size of BST
    int maxi;   // maximum value in left subtree
    int mini;   // minimum value in right subtree
    bool isBST; // is BST or not
};
// this solution is optimal
// time : O(N) Space : O(H) stack
class Solution
{
public:
    int getSize(TreeNode *root)
    {
        int ans = 0;
        solve(root, ans);
        return ans;
    }

    values solve(TreeNode *root, int &ans)
    {
        // if root == null, then is assumed to be bst of size 0 with min & max as (-inf,+inf)
        if (!root)
            return {0, INT_MIN, INT_MAX, true};

        // doing postorder traversal, why because to say about current node we should be aware of left and right subtree first
        values leftVal = solve(root->left, ans);
        values rightVal = solve(root->right, ans);

        // for current Node
        values currNodeval;

        currNodeval.size = leftVal.size + rightVal.size + 1;
        currNodeval.maxi = max(root->val, rightVal.maxi);
        currNodeval.mini = min(root->val, leftVal.mini);

        // checking if current can be BST or not
        if (leftVal.isBST && rightVal.isBST && (root->val > leftVal.maxi) && (root->val < rightVal.mini))
        {
            currNodeval.isBST = true;
        }
        else
        {
            currNodeval.isBST = false;
        }

        if (currNodeval.isBST)
        {
            ans = max(ans, currNodeval.size);
        }
        return currNodeval;
    }
};

//

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if (root->val < p->val && root->val < q->val)
            {
                // both the nodes lie in right subtree
                // move to right
                root = root->right;
            }
            else if (root->val > p->val && root->val > q->val)
            {
                // both the nodes lie in left subtree
                // move to left
                root = root->left;
            }
            else
            {
                // in this case one of both the nodes lie on either side of root
                // hence current node will be the lca
                return root;
            }
        }
        return root;
    }
};

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    return 0;
}
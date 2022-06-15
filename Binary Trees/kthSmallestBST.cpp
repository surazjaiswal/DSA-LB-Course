#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;
    Node(int val)
    {
        this->val = val;
    }
};

// method 1
// using inorder property of bst, the inorder of bst gives non-decreasing sequenece
// storing this seq and then return the kth element

// time complexity :  O(N), space complexity : O(N)
class Solution1
{
public:
    int getKthSmallest(Node *root, int k)
    {
        vector<int> vt;
        traverse(root, vt);
        return vt[k - 1];
    }

    void traverse(Node *root, vector<int> &vt)
    {
        if (!root)
            return;

        traverse(root->left, vt);
        vt.push_back(root->val);
        traverse(root->right, vt);
    }
};

// method 2
// we will do inorder traversal but will not store the traversal element, Here we will count the ordering going through the inorder
// and check the cnt at with it equals k and then return the current root->val;

// time complexity : O(N), space complexity : O(H), H = N (for skewed tree)
class Solution2
{
    int getKthSmallest(Node *root, int k)
    {
        int cnt = 0;
        return traverse(root, cnt, k);
    }

    int traverse(Node *root, int &cnt, int k)
    {
        if (!root)
            return -1;

        int LeftTraverse = traverse(root->left, cnt, k);
        if (LeftTraverse != -1)
            return LeftTraverse;

        cnt++;
        if (cnt == k)
            return LeftTraverse;

        return traverse(root->right, cnt, k);
    }
};

int main()
{

    return 0;
}
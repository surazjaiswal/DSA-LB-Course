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

bool validateBST(Node *root)
{

    // here the main idea is to check if current root->val is in the rquired range or not
    return isBST(root, LONG_MIN, LONG_MAX);
}

bool isBST(Node *root, long min, long max)
{
    // base case reached till end, means no invalid case found
    if (!root)
        return true;

    // recursion case
    if (root->val > min && root->val < max)
    {
        bool isLeftBST = isBST(root->left, min, root->val);
        bool isRightBST = isBST(root->right, root->val, max);
        return (isLeftBST && isRightBST);
    }
    else
        return false;
}

int main()
{

    return 0;
}
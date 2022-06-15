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

class Solution
{
public:
    bool twoSumBST(Node *root, int sum)
    {
        vector<int> vt;
        traverse(root, vt);

        int i = 0, j = vt.size() - 1;
        while (i < j)
        {
            int s = vt[i] + vt[j];
            if (s == sum)
                return true;
            else if (s < sum)
                i++;
            else
                j--;
        }
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

int main()
{

    return 0;
}
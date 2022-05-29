#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *buildTree()
{
    cout << "Enter value : ";
    int val;
    cin >> val;

    if (val == -1)
        return NULL;

    TreeNode *root = new TreeNode(val);
    cout << "Left TreeNode of " << val << " - ";
    root->left = buildTree();
    cout << "Right TreeNode of " << val << " - ";
    root->right = buildTree();
    return root;
}

void inOrder(TreeNode *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

pair<bool, int> chkSum(TreeNode *root)
{
    if (!root)
        return {true, 0};

    pair<bool, int> leftChk = chkSum(root->left);
    pair<bool, int> rightChk = chkSum(root->right);

    bool lChk = leftChk.first;
    bool rChk = rightChk.first;

    int sumLeft = leftChk.second;
    int sumRight = rightChk.second;

    int sumTotal = sumLeft + sumRight + root->data;

    if (root->data == (sumLeft + sumRight))
        return {true, sumTotal};

    return {false, sumTotal};
}

int main()
{

    TreeNode *root = NULL;

    root = buildTree();
    inOrder(root);
    return 0;
}

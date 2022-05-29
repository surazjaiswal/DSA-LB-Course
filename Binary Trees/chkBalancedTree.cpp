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

int getHeight(TreeNode *root)
{
    if (!root)
        return 0;

    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);

    return 1 + max(leftH, rightH);
}

bool chkBalance(TreeNode *root)
{
    if (!root)
        return true;

    bool leftBalance = chkBalance(root->left);
    bool rightBalance = chkBalance(root->right);

    if (leftBalance && rightBalance && (abs(getHeight(root->left) - getHeight(root->right)) <= 1))
        return true;
    else
        return false;
}

pair<bool, int> chkBalanceFast(TreeNode *root)
{
    if (!root)
        return {true, 0};

    pair<bool, int> leftValue = chkBalanceFast(root->left);
    pair<bool, int> rightValue = chkBalanceFast(root->right);

    bool leftBalance = leftValue.first;
    bool rightBalance = rightValue.first;

    int leftH = leftValue.second;
    int rightH = rightValue.second;

    int height = 1 + max(leftH, rightH);

    if (leftBalance && rightBalance && abs(leftH - rightH) <= 1)
        return {true, height};
    else
        return {false, height};
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    return 0;
}
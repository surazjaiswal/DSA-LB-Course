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

int getDiameter(TreeNode *root)
{
    if (!root)
        return 0;

    int leftDia = getDiameter(root->left);
    int rightDia = getDiameter(root->right);
    int midDia = 1 + getHeight(root->left) + getHeight(root->right);

    return max({leftDia, rightDia, midDia});
}

// <diameter,height>
pair<int, int> getDiameterFast(TreeNode *root)
{
    if (!root)
        return {0, 0};

    pair<int, int> leftValue = getDiameterFast(root->left);
    pair<int, int> rightValue = getDiameterFast(root->right);

    int leftDia = leftValue.first;
    int rightDia = rightValue.first;

    int leftHeight = leftValue.second;
    int rightHeight = rightValue.second;

    int diameter = max(leftDia, rightDia, (leftHeight + rightHeight));
    int height = 1 + max(leftHeight, rightHeight);

    return {diameter, height};
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    return 0;
}
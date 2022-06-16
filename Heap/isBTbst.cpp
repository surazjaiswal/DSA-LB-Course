// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

#include <bits/stdc++.h>
using namespace std;

// Structure of node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    bool isHeap(struct Node *root)
    {
        // code here
        int size = countNodes(root);
        if (isCBT(root, 0, size) && isMaxOrder(root))
        {
            return true;
        }
        return false;
    }

    int countNodes(struct Node *root)
    {
        if (!root)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isCBT(struct Node *root, int idx, int size)
    {
        if (!root)
            return true;

        if (idx > size)
        {
            return false;
        }

        bool left = isCBT(root->left, 2 * idx + 1, size);
        bool right = isCBT(root->right, 2 * idx + 2, size);

        return (left && right);
    }

    bool isMaxOrder(struct Node *root)
    {
        if (root->left == NULL && root->right == NULL)
            return true;

        if (root->right == NULL)
        {
            return (root->data > root->left->data);
        }
        else
        {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);

            if (left && right && (root->data > root->left->data) && (root->data > root->right->data))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

int main()
{

    return 0;
}
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
    int findPredecessor(Node *root, int key)
    {
        Node *pre = NULL; // assigning NULL, for the case if key not found
        // first we need to find the key node
        while (root)
        {
            if (root->val < key)
            {
                // in this case current node value is less than the key
                // which means it might be the required inorder predesessor
                // so updating it as the predessessor
                pre = root;
                // now we should try to find if there is some greater number than current root->val but less than the key value
                // which can later prove to be inorder predecessor
                // so now we move to right subtree
                root = root->right;
            }
            else
            {
                // in this case the current root->val is greater than equal to key
                // so we move to left for finding smaller value than key
                root = root->left;
            }
        }

        // if pre == null than their are cases
        // 1st is that, key value was not found in the tree
        // 2nd is that, there is no predecessor to the given key, key is the 1st element in the inorder sequence
        // for this we return -1

        // else pre != null then return the per->val

        return (pre) ? pre->val : -1;
    }

    int findSuccessor(Node *root, int key)
    {
        Node *suc = NULL; // assigning NULL, for the case if key not found
        // first we need to find the key node
        while (root)
        {
            if (root->val > key)
            {
                // in this case current node value is greter than the key
                // which means it might be the required inorder successor
                // so updating it as the successor
                suc = root;
                // now we should try to find if there is some smaller number than current root->val but greater than the key value
                // which can later prove to be inorder successor
                // so now we move to left subtree
                root = root->left;
            }
            else
            {
                // in this case the current root->val is smaller than equal to key
                // so we move to right for finding greater value than key
                root = root->right;
            }
        }
        // if suc == null than their are cases
        // 1st is that, key value was not found in the tree
        // 2nd is that, there is no successor to the given key, key is the last element in the inorder sequence
        // for this we return -1

        // else suc != null then return the suc->val

        return (suc) ? suc->val : -1;
    }
};

int main()
{

    return 0;
}
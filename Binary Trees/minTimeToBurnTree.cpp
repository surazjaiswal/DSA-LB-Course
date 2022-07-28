// https://practice.geeksforgeeks.org/problems/burning-tree/1

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
    cout << root->val << " ";
    inOrder(root->right);
}

class Solution
{
public:
    int getTime(TreeNode *root, int target)
    {

        // algo
        // 1st to map node to parent , since at a time all three connected node are burned (left, right, parent)
        // 2nd along with also find the target node
        // 3rd now burn the tree
        // for this we will need map (marking visited nodes) & queue (traversing the nodes) data structures

        unordered_map<TreeNode *, TreeNode *> mp;
        TreeNode *targetNode = nodeToParent(root, target, mp);
        int ans = solve(targetNode, mp);
        return ans;
    }

    TreeNode *nodeToParent(TreeNode *root, int target, unordered_map<TreeNode *, TreeNode *> &mp)
    {
        TreeNode *res = NULL;

        queue<TreeNode *> q;
        q.push(root);

        mp[root] = NULL;

        while (q.size())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->val == target)
                res = node;

            if (node->left)
            {
                mp[node->left] = node;
                q.push(node->left);
            }

            if (node->right)
            {
                mp[node->right] = node;
                q.push(node->right);
            }
        }

        return res;
    }

    int solve(TreeNode *targetNode, unordered_map<TreeNode *, TreeNode *> &mp)
    {
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;

        int ans = 0;

        q.push(targetNode);
        visited[targetNode] = true;

        while (q.size())
        {
            int sz = q.size();
            int flag = false;
            while (sz--)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left && !visited[node->left])
                {
                    visited[node->left] = true;
                    q.push(node->left);
                    flag = true;
                }

                if (node->right && visited[node->right])
                {
                    visited[node->right] = true;
                    q.push(node->right);
                    flag = true;
                }

                if (mp[node] && !visited[mp[node]])
                {
                    visited[mp[node]] = true;
                    q.push(mp[node]);
                    flag = true;
                }
            }

            if (flag)
                ans++;
        }
        return ans;
    }
};

int main()
{

    TreeNode *root = NULL;

    root = buildTree();
    inOrder(root);
    return 0;
}

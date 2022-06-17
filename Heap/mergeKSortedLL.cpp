#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return {};
        if (lists.size() == 1)
            return lists[0];

        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> q;
        for (auto it : lists)
        {
            ListNode *node = it;
            while (node)
            {
                q.push(make_pair(node->val, node));
                node = node->next;
            }
        }
        if (q.empty())
            return {};
        auto node = q.top();
        ListNode *ans = node.second, *temp;
        temp = ans;
        q.pop();
        while (!q.empty())
        {
            // cout<<q.top().first<<" ";
            temp->next = q.top().second;
            temp = temp->next;
            q.pop();
        }

        return ans;
    }
};

int main()
{

    return 0;
}
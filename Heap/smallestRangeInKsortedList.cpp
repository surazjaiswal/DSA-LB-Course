#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    int row;
    int col;
    node(int val, int row, int col)
    {
        this->val = val;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return (a->val > b->val);
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    priority_queue<node *, vector<node *>, compare> pq;
    int mini = INT_MAX, maxi = INT_MIN;
    // inserting all the first values from all the lists
    for (int i = 0; i < k; i++)
    {
        int num = a[i][0];
        pq.push(new node(num, i, 0));
        mini = min(mini, num);
        maxi = max(maxi, num);
    }

    int start = mini, end = maxi;

    while (!pq.empty())
    {
        node *data = pq.top();
        pq.pop();

        mini = data->val;

        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        if (data->col + 1 < n)
        {
            int num = a[data->row][data->col + 1];
            maxi = max(maxi, num);
            pq.push(new node(num, data->row, data->col + 1));
        }
        else
            break;
    }

    return (end - start + 1);
}

int main()
{

    return 0;
}
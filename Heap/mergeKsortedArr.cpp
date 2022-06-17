#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
    {
        vector<int> nums;
        for (auto it : kArrays)
        {
            for (int i : it)
            {
                nums.push_back(i);
            }
        }
        // n^2
        

        sort(nums.begin(), nums.end()); // L * log L => n^2 log n

        return nums;
    }
};

class Solution2
{
public:
    vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : kArrays)
        {
            for (int i : it)
            {
                pq.push(i);
            }
        }
        vector<int> nums;
        while (!pq.empty())
        {
            nums.push_back(pq.top());
            pq.pop();
        }

        return nums;
    }
};

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    return 0;
}
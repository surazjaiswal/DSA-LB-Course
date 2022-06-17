#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> sums;

        // n^2
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                sums.push_back(sum);
            }
        }

        sort(sums.begin(), sums.end()); // L * log L => n^2 log n^2 => n^2 log n

        return sums[sums.size() - k]; // largest is at L-1, L-2, L-3,...., L-k
    }
};

class Solution2
{
public:
    int kthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();

        // creating min heap to to k larget element in it
        // return the heap-top which will be kth largest since its a min heap

        priority_queue<int, vector<int>, greater<int>> pq;

        // n^2
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (pq.size() < k)
                {
                    pq.push(sum);
                }
                else
                {
                    if (sum < pq.top())
                    {
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }

        return pq.top();
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    return 0;
}
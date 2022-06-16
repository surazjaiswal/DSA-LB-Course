#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> pq; // max-heap creation
        // idea is to create heap of size k having k smallest element of given array
        // and the element at the top will be kth smallest
        int cnt = 0;
        for (int i = l; i <= r; i++)
        {
            if (cnt < k)
            {
                pq.push(arr[i]);
                cnt++;
            }
            else
            {
                if (arr[i] < pq.top())
                {
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
        int ans = pq.top();
        return ans;
    }
};

int main()
{

    return 0;
}
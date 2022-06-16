#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        // your code here
        vector<int> nums;
        for (int i : a)
            nums.push_back(i);
        for (int i : b)
            nums.push_back(i);

        int size = nums.size();
        int i = (size / 2) - 1;
        for (; i >= 0; i--)
        {
            heapify(nums, i, size);
        }
        return nums;
    }

    void heapify(vector<int> &nums, int idx, int size)
    {
        int largest = idx;
        int idxLeft = idx * 2 + 1;
        int idxRight = idx * 2 + 2;

        if (idxLeft < size && nums[largest] < nums[idxLeft])
        {
            largest = idxLeft;
        }

        if (idxRight < size && nums[largest] < nums[idxRight])
        {
            largest = idxRight;
        }

        if (largest != idx)
        {
            swap(nums[largest], nums[idx]);
            heapify(nums, largest, size);
        }
    }
};
int main()
{

    return 0;
}
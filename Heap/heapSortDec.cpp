#include <bits/stdc++.h>
using namespace std;

// building min heap
void heapifyMIN(vector<int> &nums, int idx, int size)
{
    int smallest = idx;
    int idxLeft = idx * 2;
    int idxRight = idx * 2 + 1;

    if (idxLeft <= size && nums[smallest] > nums[idxLeft])
    {
        smallest = idxLeft;
    }

    if (idxRight <= size && nums[smallest] > nums[idxRight])
    {
        smallest = idxRight;
    }

    if (smallest != idx)
    {
        swap(nums[smallest], nums[idx]);
        heapifyMIN(nums, smallest, size);
    }
}

void heapSortMIN(vector<int> &nums, int size)
{

    // swap first and last node
    int n = size;
    while (n > 1)
    {
        swap(nums[1], nums[n]); // swapping first and last element, like sending smallest element to the end and blocking it
        n--;                    // reducing the size, blocking the sorted part
        heapifyMIN(nums, 1, n); // 1st idx is to be heapified
    }
}

int main()
{
    vector<int> nums = {-1, 54, 53, 55, 52, 50};

    // building min heap for given arr
    int n = nums.size() - 1;
    int i = n / 2; // since node from n/2 + 1 to n are leaf nodes, no need to process them as we assume that they are already heapified

    for (; i > 0; i--)
        heapifyMIN(nums, i, n);

    for (int i = 1; i <= n; i++)
        cout << nums[i] << " ";
    cout << endl;

    heapSortMIN(nums, n);

    for (int i = 1; i <= n; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
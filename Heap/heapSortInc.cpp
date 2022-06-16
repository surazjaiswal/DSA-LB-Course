#include <bits/stdc++.h>
using namespace std;

// building max heap
void heapify(vector<int> &nums, int idx, int size)
{
    int largest = idx;
    int idxLeft = idx * 2;
    int idxRight = idx * 2 + 1;

    if (idxLeft <= size && nums[largest] < nums[idxLeft])
    {
        largest = idxLeft;
    }

    if (idxRight <= size && nums[largest] < nums[idxRight])
    {
        largest = idxRight;
    }

    if (largest != idx)
    {
        swap(nums[largest], nums[idx]);
        heapify(nums, largest, size);
    }
}

void heapSort(vector<int> &nums, int size)
{

    // swap first and last node
    int n = size;
    while (n > 1)
    {
        swap(nums[1], nums[n]); // swapping first and last element, like sending largest to the end and blocking it
        n--;                    // reducing the size, blocking the sorted part
        heapify(nums, 1, n);    // 1st idx is to be heapified
    }
}

int main()
{
    vector<int> nums = {-1, 54, 53, 55, 52, 50};

    // step1 building max heap for given arr
    int n = nums.size() - 1;
    int i = n / 2; // since node from n/2 + 1 to n are leaf nodes, no need to process them as we assume that they are already heapified

    for (; i > 0; i--)
        heapify(nums, i, n);

    for (int i = 1; i <= n; i++)
        cout << nums[i] << " ";
    cout << endl;

    heapSort(nums, n);

    for (int i = 1; i <= n; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
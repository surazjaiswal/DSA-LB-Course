#include <bits/stdc++.h>
using namespace std;

void heapifyMAX(vector<int> &nums, int idx, int size)
{
    int largest = idx;          // assuming that current idx position is the largest
    int idxLeft = idx * 2;      // left child idx
    int idxRight = idx * 2 + 1; // right child idx

    // check if largest is greater than h=its child nodes
    if (idxLeft < size && nums[largest] < nums[idxLeft])
    {
        largest = idxLeft;
    }

    if (idx < size && nums[largest] < nums[idxRight])
    {
        largest = idxRight;
    }

    // check if largest changed
    if (largest != idx)
    {
        // means larger value is found, now swap it with that
        swap(nums[idx], nums[largest]);
        // now also heapify the new largest postion
        heapifyMAX(nums, largest, size);
    }
}

void heapifyMIN(vector<int> &nums, int idx, int size)
{
    int smallest = idx;
    int idxLeft = idx * 2 + 1;
    int idxRight = idx * 2 + 2;

    if (idxLeft < size && nums[smallest] > nums[idxLeft])
    {
        smallest = idxLeft;
    }

    if (idxRight < size && nums[smallest] > nums[idxRight])
    {
        smallest = idxRight;
    }

    if (smallest != idx)
    {
        swap(nums[smallest], nums[idx]);
        heapifyMIN(nums, smallest, size);
    }
}

// for 0 based indexing
// vector<int> buildMinHeap(vector<int> &arr)
// {
//     int n = arr.size();
//     int i = (n/2) - 1; // [n/2,n] consists of leaf nodes
//     for(;i>=0;i--){
//         heapify(arr,i,n);
//     }
//     return arr;
// }

int main()
{

    vector<int> nums = {-1, 54, 53, 55, 52, 50};
    int n = nums.size() - 1;
    int i = n / 2; // since node from n/2 + 1 to n are leaf nodes, no need to process them as we assume that they are already heapified
    for (; i > 0; i--)
    {
        heapifyMIN(nums, i, n);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
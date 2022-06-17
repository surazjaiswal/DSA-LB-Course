// https://leetcode.com/problems/find-median-from-data-stream/

#include <bits/stdc++.h>
using namespace std;

// to find median we need to have mid element for odd length and mid & mid+1 for even length
// in brute force we add new num and then sort them to get median takes (n^2 log n) time [TLE]
// here we see that we only need mid elements
// what if there is way to have to always get mid elements, and every insertion gets sorted to holds new mid elements required
// if we divide list in to two halfs
// for odd length   [5,3,4,2,6] => [5,3,4] [2,6]
// for even length  [5,3,4,2]   => [5,3] [4,2]
// and create max-heap for left half and min-heap right part
// considering max-heap will always contain 1 element more than min-heap
// the top of the max-heap will always hold the mid-th element, and top of min-heap always hold the (mid+1)th element
// after every intertion mid values will be updated as internal sorting in the heap
// here intertion consists of many cases
// hence we got what we required

class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        // check if max heap is empty, then add num to it
        if (maxHeap.size() == 0)
        {
            maxHeap.push(num);
        }
        // check if size of min & max heap are same
        else if (minHeap.size() == maxHeap.size())
        {
            // value will be added to max heap
            // but check if (top of num > minHeap) then larger number is moved to minHeap that is right half of the array
            // and top of minHeap is to be shitfted to maxHeap, as maxHeap should awlays contain 1 more element
            if (num > minHeap.top())
            {
                // then we have to shift the smaller number (top of minHeap) to maxHeap that is left half of the list
                int temp = minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(temp);
            }
            else
            {
                // num < maxHeap.top then simply add it maxHeap
                maxHeap.push(num);
            }
        }
        else
        {
            // size of both heap are different
            // the only case will be maxHeap has 1 more element than minHeap
            // the next num will be added to min heap accordingly

            // if num < maxHeap.top then this num is to be added to maxHeap, by shifting maxHeap.top to minHeap
            if (num < maxHeap.top())
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(temp);
            }
            else
            {
                // if the num > maxHeap.top then simply add it to minHeap
                minHeap.push(num);
            }
        }
    }

    double findMedian()
    {
        if (maxHeap.size() > minHeap.size())
        {
            // odd length, return only mid element -> maxHeap top element
            return maxHeap.top();
        }
        else
        {
            // even length, return avg of maxHeap.top and minHeap.top
            return ((maxHeap.top() + minHeap.top()) / 2.0);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{

    return 0;
}
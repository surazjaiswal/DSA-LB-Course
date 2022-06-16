#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int size;
    int arr[100];
    heap()
    {
        size = 0;
    }

    void insert(int val)
    {
        // increase the position of insertion
        // new value is inserted at last

        size++;
        int index = size;
        arr[index] = val;

        // placing the newly added value to its correct postion
        // first checking if it satisfies the max-heap property
        // check if new added value if grater than its parent
        // if yes then swap both values, and again continue to check again until condition is satisfied
        // and if conditon is statisfied then values is placed correctly

        while (index > 1)
        {
            int parent = index / 2; // getting parent of new added value
            if (arr[parent] < val)
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void deleteNode()
    {
        // step 1: swap root node with last node
        swap(arr[1], arr[size]);

        // step 2: delete the last node
        // this way of deleting maintain the complete binary tree consistency
        size--;

        // step 3: place the root node at its correct position
        int idx = 1;
        while (idx < size)
        {
            int idxLeft = idx * 2;
            int idxRight = idx * 2 + 1;

            if (idxLeft < size && arr[idx] < arr[idxLeft])
            {
                swap(arr[idx], arr[idxLeft]);
                idx = idxLeft;
            }
            else if (idxRight < size && arr[idx] < arr[idxRight])
            {
                swap(arr[idx], arr[idxRight]);
                idx = idxRight;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteNode();
    h.print();

    return 0;
}
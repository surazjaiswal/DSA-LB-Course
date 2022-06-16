#include <bits/stdc++.h>
using namespace std;

int main()
{

    // max heap creation
    priority_queue<int> pq_max;
    pq_max.push(4);
    pq_max.push(3);
    pq_max.push(7);
    pq_max.push(2);
    pq_max.push(8);

    cout << pq_max.top() << endl;
    pq_max.pop();
    cout << pq_max.top() << endl;

    // min heap creation
    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq_min.push(4);
    pq_min.push(3);
    pq_min.push(7);
    pq_min.push(2);
    pq_min.push(8);

    cout << pq_min.top() << endl;
    pq_min.pop();
    cout << pq_min.top() << endl;

    return 0;
}

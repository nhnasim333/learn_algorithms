#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    // This comparator is used to create a min-heap based on the second element of the pairs
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        // Compare based on the second element (priority)
        return a.second > b.second;
    }
};

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({1, 5});
    pq.push({2, 3});
    pq.push({0, 1});
    while (!pq.empty())
    {
        // greater func always returns the first element with the lowest priority
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}
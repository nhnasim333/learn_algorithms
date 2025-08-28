#include <bits/stdc++.h>
using namespace std;

struct cmp
{
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
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}
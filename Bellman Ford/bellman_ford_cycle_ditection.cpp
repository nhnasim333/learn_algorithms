#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

int dis[105];
vector<Edge> edge_list;
int n, e;

void bellman_ford()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int w = ed.w;

            if (dis[a] != INT_MAX && dis[a] + w < dis[b])
                dis[b] = dis[a] + w;
        }
    }

    bool has_cycle = false;
    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        int w = ed.w;

        if (dis[a] != INT_MAX && dis[a] + w < dis[b])
        {
            has_cycle = true;
            break;
        }
    }

    if (has_cycle)
    {
        cout << "Graph contains negative weight cycle" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << i << "->" << dis[i] << endl;
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge_list.push_back(Edge(a, b, w));
    }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dis[0] = 0;

    bellman_ford();

    return 0;
}
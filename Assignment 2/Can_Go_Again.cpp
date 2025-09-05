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

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge_list.push_back(Edge(a, b, w));
    }

    int src;
    cin >> src;

    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; i++)
        cin >> queries[i];

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        bool changed = false;
        for (auto &ed : edge_list)
        {
            if (dist[ed.a] != LLONG_MAX && dist[ed.a] + ed.w < dist[ed.b])
            {
                dist[ed.b] = dist[ed.a] + ed.w;
                changed = true;
            }
        }
        if (!changed)
            break;
    }

    for (auto &ed : edge_list)
    {
        if (dist[ed.a] != LLONG_MAX && dist[ed.a] + ed.w < dist[ed.b])
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
    }

    for (int d : queries)
    {
        if (dist[d] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dist[d] << endl;
    }

    return 0;
}

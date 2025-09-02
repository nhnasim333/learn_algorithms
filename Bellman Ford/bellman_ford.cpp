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
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edge_list;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge_list.push_back(Edge(a, b, w));
    }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dis[0] = 0;

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

    for (int i = 0; i < n; i++)
        cout << i << "->" << dis[i] << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    long long int adj_mat[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = LLONG_MAX;
        }
    }

    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        adj_mat[a][b] = min(adj_mat[a][b], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    int src;
    int q;
    cin >> src >> q;
    bool cycle = false;

    for (int i = 1; i <= n; i++)
    {
        if (adj_mat[i][i] < 0)
            cycle = true;
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        while (q--)
        {
            int d;
            cin >> d;
            if (adj_mat[src][d] == LLONG_MAX)
                cout << "Not Possible" << endl;
            else
                cout << adj_mat[src][d] << endl;
        }
    }
    return 0;
}

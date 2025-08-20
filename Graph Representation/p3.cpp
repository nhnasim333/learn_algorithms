#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj_mat[100];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a].push_back(b);
        adj_mat[b].push_back(a);
    }
    int N;
    cin >> N;
    cout << adj_mat[N].size() << endl;
    return 0;
}
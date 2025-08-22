#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
int n, m;

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int dfs(int i, int j) {
    vis[i][j] = true;
    int cnt = 1;
    for (auto d : directions) {
        int ni = i + d.first, nj = j + d.second;
        if (valid(ni, nj) && !vis[ni][nj] && grid[ni][nj] == '.') {
            cnt += dfs(ni, nj);
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    vector<int> apartment_sizes;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && grid[i][j] == '.') {
                apartment_sizes.push_back(dfs(i, j));
            }
        }
    }
    if (apartment_sizes.empty()) {
        cout << 0 << endl;
    } else {
        sort(apartment_sizes.begin(), apartment_sizes.end());
        for (int size : apartment_sizes) {
            cout << size << " ";
        }
        cout << endl;
    }
    return 0;
}
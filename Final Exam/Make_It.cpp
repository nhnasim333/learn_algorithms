#include <bits/stdc++.h>
using namespace std;
int dp[100005];

int make_it(int i, int target)
{
    if (i == target)
        return 1;
    if (i > target)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    dp[i] = make_it(i + 3, target) || make_it(i * 2, target);
    return dp[i];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        cout << (make_it(1, n) ? "YES" : "NO") << endl;
    }

    return 0;
}
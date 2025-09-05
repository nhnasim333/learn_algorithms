#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int left = 0, right = n - 1;
        long long bestHeight = 0;
        int ansL = 0, ansR = n - 1;

        while (left < right)
        {
            long long height = min(arr[left], arr[right]);

            if (height > bestHeight)
            {
                bestHeight = height;
                ansL = left;
                ansR = right;
            }

            if (arr[left] < arr[right])
                left++;
            else
                right--;
        }

        cout << ansL << " " << ansR << endl;
    }

    return 0;
}

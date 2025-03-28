#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<i64> pre(n, 0);
    vector<i64> sur(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            pre[i] = a[i];
        if (i)
            pre[i] += pre[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < 0)
            sur[i] = abs(a[i]);
        if (i + 1 < n)
            sur[i] += sur[i + 1];
    }
    i64 res = 0;
    for (int i = 0; i < n; i++)
    {
        if (pre[i] > res)
        {
            res = pre[i];
        }
        if (sur[i] > res)
        {
            res = sur[i];
        }
        //枚举每一个位置（i）的最优解
        if (i + 1 < n)
        {
            if (pre[i] + sur[i + 1] > res)
            {
                res = pre[i] + sur[i + 1];
            }
        }
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

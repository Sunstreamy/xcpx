#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n + 1), c(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = 2 * (n - i);
    }
    for (int i = n; i > 0; i--)
    {
        d[i] = 2 * (i - 1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] - c[i] <= 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = n; i > 0; i--)
    {
        if (a[i] - d[i] <= 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
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

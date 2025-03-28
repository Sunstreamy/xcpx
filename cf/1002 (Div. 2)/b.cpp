#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (k == n)
    {
        for (int i = 1, j = 1; i < n; i += 2, ++j)
        {
            if (a[i] != j)
            {
                cout << j << endl;
                return;
            }
        }
        cout << n / 2 + 1 << endl;
        return;
    }
    for (int i = 1; i <= n - k + 1; i++)
    {
        if (a[i] != 1)
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << 2 << endl;
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

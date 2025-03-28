#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n), b(n), c(n);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        c[i] = b[i] - a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (c[i] > 0)
            flag++;
        if (flag >= 2)
        {
            cout << "NO" << endl;
            return;
        }
    }
    i64 mn = 1e9 + 5;
    i64 temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] > 0)
        {
            temp = c[i];
        }
        if (abs(c[i]) < mn && c[i] <= 0)
            mn = abs(c[i]);
    }
    if (abs(temp) > mn)
        cout << "NO" << endl;
    else
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

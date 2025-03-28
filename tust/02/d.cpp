#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        while (a[i] % 10 != 2 && a[i] % 10 != 0)
        {
            a[i] += a[i] % 10;
        }
        if (a[i] % 10 == 2)
        {
            a[i] %= 20;
        }
    }
    cout << (a == vector<i64>(n, a[0]) ? "Yes\n" : "No\n");
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

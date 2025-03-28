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
    vector<i64> b(n);

    for (i64 i = 0; i < n;i++)
    {
        cin >> a[i];
    }

    for (i64 i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    set<i64> set_a(a.begin(), a.end());
    set<i64> set_b(b.begin(), b.end());
    set<i64> sum;

    for (i64 x : set_a)
    {
        for (i64 y : set_b)
        {
            sum.insert(x + y);
        }
    }

    if (sum.size() >= 3)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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

#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005

void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (a + b + c < n)
    {
        cout << "No" << endl;
        return;
    }
    int k = a + b + c - n;
    if (max(k - a, 0) + max(k - b, 0) <= min(c, k))
    {
        cout << "Yes" << endl;
        return;
    }
    else
        cout << "No" << endl;
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
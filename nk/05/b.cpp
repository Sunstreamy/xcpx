#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005
void solve()
{
    i64 n, t, k;
    cin >> n >> t >> k;
    if (n - k < t)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << min((n - k) / t, k + 1) << endl;
        return;
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

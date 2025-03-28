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
    for (int ans = 0; ans <= 9; ans++)
    {
        string s = to_string(n - ans);
        int md = 0;
        for (auto c : s)
        {
            if (c <= '7')
            {
                md = max(md, c - '0');
            }
        }
        if (ans >= 7 - md)
        {
            cout << ans << endl;
            return;
        }
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
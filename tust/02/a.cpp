#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1] + (s[i - 1] == 'W' ? 1 : 0);
    }

    int ans = k;
    for (int i = 0; i <= n - k; ++i)
    {
        int cur = pre[i + k] - pre[i];
        if (cur < ans)
        {
            ans = cur;
        }
    }

    cout << ans << endl;
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

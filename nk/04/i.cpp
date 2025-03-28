#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if (n < 10)
    {
        cout << 0 << endl;
        return;
    }
    vector<int> pre(n, 0);
    pre[0] = (s[0] == 'u');
    for (int i = 1; i < n; ++i)
    {
        pre[i] = pre[i - 1] + (s[i] == 'u');
    }
    int ans = 0;
    for (int i = 0; i <= n - 8; ++i)
    {
        if (s[i] == 'u' &&
            s[i + 1] == 'w' &&
            s[i + 2] == 'a' &&
            s[i + 3] == 'w' &&
            s[i + 4] == 'a' &&
            s[i + 5] == 'u' &&
            s[i + 6] == 'w' &&
            s[i + 7] == 'a')
        {
            if (i >= 2)
            {
                ans += pre[i - 2];
            }
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

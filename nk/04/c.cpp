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
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        if (s == "?")
        {
            cout << 2 << endl;
            return;
        }
        else
            cout << 1 << endl;
        return;
    }
    s = " " + s;
    int cnt = count(s.begin(), s.end(), '?');
    int num = 1, num_1 = 1;
    for (int i = 1; i <= cnt; i++)
    {
        num *= 2;
        num %= M;
    }
    for (int i = 1; i <= cnt - 1; i++)
    {
        num_1 *= 2;
        num_1 %= M;
    }
    i64 ans = 0;
    if (s[1] != '?' && s[n] != '?')
    {
        if (s[1] == s[n])
        {
            ans = 1ll * num * (n - 2) % M;
        }
        else
            ans = 1ll * num * 2 % M;
    }
    else
        ans = 1ll * num_1 * n % M;
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

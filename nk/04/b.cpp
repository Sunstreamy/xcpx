#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
const int k = 1e9 + 7;

bool balance(string &s)
{
    int cnt01 = 0, cnt10 = 0;
    for (int i = 0; i < s.size() - 1; ++i)
    {
        if (s.substr(i, 2) == "01")
        {
            cnt01++;
        }
        else if (s.substr(i, 2) == "10")
        {
            cnt10++;
        }
    }
    return cnt01 == cnt10;
}

int val(string &s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        string new_s = s;
        new_s[i] = (new_s[i] == '0') ? '1' : '0';
        if (balance(new_s))
        {
            ans++;
        }
    }
    return ans;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> wenhao;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '?')
        {
            wenhao.push_back(i);
        }
    }

    int p = wenhao.size();
    i64 res = 0;

    for (int i = 0; i < (1 << p); ++i)
    {
        string new_s = s;
        for (int j = 0; j < p; ++j)
        {
            if ((i >> j) & 1)
            {
                new_s[wenhao[j]] = '1';
            }
            else
            {
                new_s[wenhao[j]] = '0';
            }
        }
        res = (res + val(new_s)) % k;
    }
    cout << res << endl;
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
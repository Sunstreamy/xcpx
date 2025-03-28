#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int M = 1e9 + 7;
#define N 200005

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<int> flag(n + 1);
    bool ok = false;
    for (int i = 1; i <= n; i++)
    {
        if (mp[a[i]] == 1)
        {
            flag[i] = 1;
            ok = true;
        }
    }
    if (!ok)
    {
        cout << 0 << endl;
        return;
    }
    int r1 = 0, r2 = 0;
    int l = 0;
    for (int i = 1; i <= n; i++)
    {
        if (flag[i] == 0)
        {
            l = 0;
        }
        else
        {
            if (l == 0)
                l = i;
            if (i - l >= r2 - r1)
            {
                r1 = l;
                r2 = i;
            }
        }
    }
    cout << r1 << " " << r2 << endl;
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
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

void solve()
{
    int n;
    cin >> n;
    vector<vector<i64>> a(n, vector<i64>(n));
    vector<i64> cnt(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }

        for (int j = n - 1; j >= 0; j--)
        {
            if (a[i][j] == 1)
            {
                cnt[i]++;
            }
            else
                break;
        }
    }
    sort(cnt.begin(), cnt.end());
    i64 ans = 0;
    for (auto x : cnt)
    {
        if (x >= ans)
        {
            ans++;
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
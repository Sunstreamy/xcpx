#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<i64>> grid(n + 1, vector<i64>(m + 1, 0));

    vector<i64> d1(n + m + 1, 0); 
    vector<i64> d2(n + m + 1, 0); 

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> grid[i][j];
            d1[i + j] += grid[i][j];     
            d2[i - j + m] += grid[i][j]; 
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            i64 cur = d1[i + j] + d2[i - j + m] - grid[i][j];
            ans = max(ans, cur);
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
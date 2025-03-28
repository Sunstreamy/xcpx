#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
const int M = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    map<int, int> occ;
    int ans = n + 1;
    int l = 0;

    for (int r = 0; r < n; ++r)
    {
        if (occ.find(a[r]) != occ.end() && occ[a[r]] >= l)
        {
            ans = min(ans, r - occ[a[r]] + 1);
            l = occ[a[r]] + 1;
        }
        occ[a[r]] = r;
    }

    ans = (ans == n + 1) ? -1 : ans;
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005

int b[N];
pair<int, int> a[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        b[i] = a[i].first;
    }
    a[n].first = 1e9;
    sort(a, a + n);
    int l = a[0].second, r = a[0].second;
    int ma = max(a[0].first * 2, a[n - 1].first);
    int res = ma - min(a[0].first * 2, a[1].first);
    for (int i = 1; i < n; i++)
    {
        while (a[i].second < l)
        {
            l--;
            ma = max(ma, b[l] * 2);
        }
        while (a[i].second > r)
        {
            r++;
            ma = max(ma, b[r] * 2);
        }
        res = min(res, ma - min(a[0].first * 2, a[i + 1].first));
    }
    cout << res << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}

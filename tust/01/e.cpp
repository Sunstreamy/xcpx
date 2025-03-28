#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
void solve()
{
    int l, d, v, g, r;
    cin >> l >> d >> v >> g >> r;
    double t1 = 1.0 * d / v;
    int T = g + r;
    double temp = fmod(t1, T);
    double ans = 0;
    if (temp < g)
    {
        ans = t1 + (l - d) * 1.0 / v;
    }
    else
    {
        ans = t1 + (T - temp) + (l - d) * 1.0 / v;
    }
    cout << fixed << setprecision(8) << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

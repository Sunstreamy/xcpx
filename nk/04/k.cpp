#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
void solve()
{
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    int mx = x * a;
    if (y * b > mx)
    {
        mx = y * b;
    }
    if (z * c > mx)
    {
        mx = z * c;
    }
    cout << mx << endl;
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

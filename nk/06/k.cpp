
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005
void solve()
{
    int x, y;
    cin >> x >> y;
    int diff1 = y - 2 * x - 1;
    if (diff1 >= 0 && diff1 % 4 == 0)
    {
        cout << "YES" << endl;
        return;
    }

    int diff2 = 2 * x - y + 1;
    if (diff2 >= 0 && diff2 % 4 == 0)
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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

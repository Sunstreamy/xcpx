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
    if (y == x + 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        int k = x + 1 - y;
        if (k > 0 && k % 9 == 0)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
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

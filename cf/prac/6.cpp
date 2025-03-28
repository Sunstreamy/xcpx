#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005
void solve()
{
    int n;
    cin >> n;
    if (n == 6)
    {
        cout << "1 1 2 3 1 2" << endl;
        return;
    }

    for (int i = 1; i <= n - 2; i++)
    {
        cout << i << " ";
    }
    cout << 1 << " " << 2;
    cout << endl;
    return;
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

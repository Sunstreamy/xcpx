#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }

    int k = b[0];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            c[i] = min((k - a[i]), a[i]);
        }
        else
        {
            if (k - a[i] >= c[i - 1] && a[i] >= c[i - 1])
            {
                c[i] = min((k - a[i]), a[i]);
            }
            else if (k - a[i] < c[i - 1] && a[i] < c[i - 1])
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                if (k - a[i] >= c[i - 1])
                {
                    c[i] = k - a[i];
                }
                else
                    c[i] = a[i];
            }
        }
    }
    cout << "YES" << endl;
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

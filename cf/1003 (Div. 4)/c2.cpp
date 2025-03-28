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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    if (is_sorted(a.begin(), a.end()))
    {
        cout << "YES" << endl;
        return;
    }

    sort(b.begin(), b.end());

    vector<int> c(n);
    c[0] = a[0];

    for (int j = 0; j < m; ++j)
    {
        int num = b[j] - a[0];
        if (num < c[0])
        {
            c[0] = num;
        }
    }

    for (int i = 1; i < n; ++i)
    {

        auto it = lower_bound(b.begin(), b.end(), a[i] + c[i - 1]);
        if (it == b.end())
        {

            if (a[i] >= c[i - 1])
            {
                c[i] = a[i];
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {

            int temp = *it - a[i];
            if (a[i] >= c[i - 1])
            {
                c[i] = min(a[i], temp);
            }
            else
            {
                c[i] = temp;
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
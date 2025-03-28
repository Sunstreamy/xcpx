#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m), b(k);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
    }
    if (n == k)
    {
        for (int i = 0; i < m; i++)
        {
            cout << 1;
        }
        cout << endl;
        return;
    }
    else if (n - k >= 2)
    {
        for (int i = 0; i < m; i++)
        {
            cout << 0;
        }
        cout << endl;
        return;
    }
    else
    {
        vector<bool> konwn(n + 1, false);
        for (int i = 0; i < k; i++)
        {
            konwn[b[i]] = true;
        }
        for(int i = 0; i < m; i++)
        {
            if(konwn[a[i]])
            {
                cout << 0;
            }
            else
            {
                cout << 1;
            }
        }
        cout << endl;
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

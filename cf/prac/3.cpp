#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int flag = 0;
    int d = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            flag = -1;
            break;
        }
        if (flag == 0 && a[i] - b[i] != 0)
        {
            flag = 1;
            d = a[i] - b[i];
        }
        else if (flag == 1 && a[i] - b[i] != d)
        {
            if (a[i] == b[i])
            {
                flag = 2;
            }
            else
            {
                flag = -1;
                break;
            }
        }
        else if (flag == 2 && a[i] - b[i] != 0)
        {
            flag = -1;
            break;
        }
    }
    if (flag > 2 || flag == -1)
    {
        cout << "NO" << endl;
    }
    else
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

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

    string s;
    cin >> s;

    int l = -1, r = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 's')
            l = i;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'p')
            r = i;
    }

    if (r < l)
        cout << "NO"<<endl;
    else
    {
        if (l == -1 || r == n || r == n - 1 || l == 0)
        {
            cout << "YES"<<endl;
        }
        else
        {
            cout << "NO"<<endl;
        }
    }

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

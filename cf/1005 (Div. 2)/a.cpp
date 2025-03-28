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

    bool flag1 = false;
    for (char c : s)
    {
        if (c == '1')
        {
            flag1 = true;
            break;
        }
    }
    if (!flag1)
    {
        cout << 0 << endl;
        return;
    }

    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            idx = i;
            break;
        }
    }

    int flag = 0;
    for (int i = idx; i < n - 1; i++)
    {
        if (s[i] == '0' && s[i + 1] == '1')
        {
            flag++;
        }
        if (s[i] == '1' && s[i + 1] == '0')
        {
            flag++;
        }
    }
    cout << flag + 1 << endl;
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

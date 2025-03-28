#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005
void solve()
{
    string s;
    cin >> s;
    int idx_0 = 0, idx_1 = 0;
    int l = 0;
    int n = s.size();
    bool all_1 = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            all_1 = false;
    }
    if (all_1)
    {
        cout << 1 << " " << n << " " << 1 << " " << 1 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            idx_0 = i;
            break;
        }
    }
    int need = n - idx_0;
    string tar = s.substr(idx_0, need);
    int cnt = 0;
    for (int i = 0; i <= n - need; i++)
    {
        string cur = s.substr(i, need);
        int temp = 0;
        for (int j = 0; j < need; j++)
        {
            if (((cur[j] - '0') ^ (tar[j] - '0')) == 1)
            {
                temp++;
            }
            else if (((cur[j] - '0') ^ (tar[j] - '0')) == 0)
            {
                break;
            }
        }
        if (temp > cnt)
        {
            l = i + 1;
            cnt = temp;
        }
    }
    cout << 1 << " " << n << " " << l << " " << l + need - 1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }

    return 0;
}

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
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int mx = s[i] - '0';
        int idx = i;
        for (int j = i + 1; j < n && j < i + 10;j++)
        {
            int cur = s[j] - '0' - (j - i);
            if(cur>mx)
            {
                mx = cur;
                idx = j;
            }
        }
        for (int j = idx; j > i;j--)
        {
            swap(s[j], s[j - 1]);
            //相当于把s【i】直接换成了后面那个贪心到的数字  因此后面还需要减去移动过来的成本
        }
        s[i] = s[i] - (idx - i);
    }
    cout << s << endl;
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

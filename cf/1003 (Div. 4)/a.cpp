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
    string cur = s;
    while (cur.length() > 1)
    {
        bool flag = false;
        for (int i = 0; i < cur.length(); i++)
        {
            if (cur[i] == cur[i + 1])
            {
                cur[i] = 'a';
                cur.erase(i + 1, 1);
                flag= true;
                break;
            }
        }
        if(!flag)
        {
            break;
        }

    }
    cout << cur.length() << endl    ;
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

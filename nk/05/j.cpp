#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
const int M = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    i64 v = 0;
    i64 dis = 0;
    i64 v1 = 0;
    bool lihe = false;
    for (int i = 0; i < n; ++i)
    {
        if (lihe)
        {
            v = v1;
            lihe = false;
        }
        if (s[i] == '0')
        {
            v += 10;
        }
        else if (s[i] == '1')
        {
            v = max((i64)0, v - 5);
        }
        else if (s[i] == '2')
        {
            v1 = v;
            v = max((i64)0, v - 10);
            lihe = true;
        }
        dis += v;
    }
    cout << dis << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
void solve()
{
    string s;
    cin >> s;
    map<char, int> cnt;
    for (char c : s)
    {
        if (cnt.find(c) != cnt.end())
        {
            cnt[c]++;
        }
        else
        {
            cnt[c] = 1;
        }
    }
    if (cnt['c'] == 1 && cnt['d'] == 1 && cnt['e'] == 1 && cnt['n'] == 1 && cnt['o'] == 2 && cnt['r'] == 1 && cnt['w'] == 1)
    {
        cout << "happy new year" << endl;
    }
    else
    {
        cout << "I AK IOI" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

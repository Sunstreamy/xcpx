#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int headpay = 1e9 + 1, tailpay = 1e9 + 1;
    int idxhead = 1, idxtail = n - 2;
    if (s[0] == '0')
    {
        while (idxhead < n && s[idxhead] == '0')
        {
            idxhead++;
        }
        if (idxhead < n - 1)
        {
            headpay = idxhead;
        }
    }
    if (s[n - 1] == '0')
    {
        while (idxtail >= 0 && s[idxtail] == '0')
        {
            idxtail--;
        }
        if (idxtail >= 0)
        {
            tailpay = n - 1 - idxtail;
        }
    }
    if (k >= tailpay)
    {
        k -= tailpay;
        swap(s[n - 1], s[idxtail]);
    }

    if (k >= headpay)
    {
        k -= headpay;
        swap(s[0], s[idxhead]);
    }
    int ans = 0, temp;
    for (int i = 0; i < n - 1;i++)
    {
        temp = (s[i] - '0') * 10 + s[i + 1] - '0';
        ans += temp;
    }
    cout << ans << endl;
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

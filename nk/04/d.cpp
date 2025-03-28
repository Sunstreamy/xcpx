#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    if (n < m)
    {
        swap(n, m);
        swap(a, b);
    }
    map<int, int> mp;
    for (auto &i : a)
    {
        mp[i]++;
    }
    int sum = 0;
    for (auto &i : b)
    {
        if (mp[i])
            mp[i]--;
        else
            sum++;
    }
    int ans = 0;
    for (auto &[x, y] : mp)
    {
        if (y & 1)
            ans++;
    }
    if (sum >= ans)
    {
        ans = sum;
    }
    //就是说  反正长字符串中都有匹配不掉短字符串中的数不如先变成让短字符串中只有奇数个的字符  这样还可以多消掉一些
    else
    {
        ans -= sum;
        ans /= 2;
        ans += sum;
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
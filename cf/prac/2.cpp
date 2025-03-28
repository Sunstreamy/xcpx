#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    if (n == k || n == 1)
    {
        cout << 1 << endl;
        return;
    }
    vector<pair<int, int>> vec(cnt.begin(), cnt.end());
    sort(vec.begin(), vec.end(), cmp);
    for (const auto &p : vec)
    {
        if (k <= 0)
            break;
        if (p.second <= k)
        {
            k -= p.second;
            cnt.erase(p.first);
        }
        else
        {
            break;
        }
    }

    cout << cnt.size() << endl;
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

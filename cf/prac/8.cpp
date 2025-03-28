#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005
void solve()
{
    i64 n, x, y;
    cin >> n >> x >> y;
    vector<i64> v(n);
    i64 sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    i64 L = sum - y;
    i64 R = sum - x;
    sort(v.begin(), v.end());
    i64 cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        i64 t1 = L - v[i];
        i64 t2 = R - v[i];
        int left = i + 1;
        if (left >= n)
            break;
        auto start = lower_bound(v.begin() + left, v.end(), t1);
        auto end = upper_bound(v.begin() + left, v.end(), t2);
        cnt += end - start;
    }
    cout << cnt << endl;
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

#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n == 1)
    {
        cout << a[0] << '\n';
        return;
    }

    i64 ans = accumulate(a.begin(), a.end(), (i64)0);
    vector<i64> current = a;

    while (current.size() > 1)
    {
        i64 diff = abs(current.back() - current.front());
        ans = max(ans, diff);

        vector<i64> next_seq;
        for (size_t i = 0; i < current.size() - 1; ++i)
        {
            next_seq.push_back(current[i + 1] - current[i]);
        }
        current = move(next_seq);
    }

    if (!current.empty())
    {
        ans = max(ans, abs(current[0]));
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
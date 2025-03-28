#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> b(n), w(m);

    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < m; ++i)
        cin >> w[i];

    sort(b.rbegin(), b.rend());
    sort(w.rbegin(), w.rend());

    // 白球前缀和
    vector<i64> prew(m + 1);
    for (int i = 0; i < m; ++i)
        prew[i + 1] = prew[i] + w[i];

    // 黑球前缀和及后缀最大值
    vector<i64> preb(n + 1);
    for (int i = 0; i < n; ++i)
        preb[i + 1] = preb[i] + b[i];

    vector<i64> max_b(n + 2);
    i64 cur_max = -1e18;
    for (int i = n; i >= 0; --i)
    {
        cur_max = max(cur_max, preb[i]);
        max_b[i] = cur_max;
    }

    i64 ans = max_b[0]; // 只选黑球的情况
    if(ans<0)
    {
        cout<<0<<endl;
        return;
    }

    for (int k = 1; k <= m; ++k)
    {
        if (k > n)
            break; // 黑球不足无法满足至少k个
        ans = max(ans, prew[k] + max_b[k]);
    }
    ans = max(ans, 0LL);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
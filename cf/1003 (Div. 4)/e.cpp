#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int M = 1e9 + 7;
#define N 200005

bool cmp(const int &i, const int &j, const vector<i64> &sums)
{
    return sums[i] > sums[j];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<i64> sums(n, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            sums[i] += a[i][j];     
        }
    }

    vector<int> idx(n);
    for (int i = 0; i < n; ++i)
        idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int i, int j)
         { return cmp(i, j, sums); });
    vector<i64> arr;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            arr.push_back(a[idx[i]][j]);
        }
    }

    i64 ans = 0;
    i64 pre = 0;
    for (int i = 0; i < n * m; ++i)
    {
        pre += arr[i];
        ans += pre;
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
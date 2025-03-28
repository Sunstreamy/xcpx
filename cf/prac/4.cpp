#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005
void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    l--;
    vector<int> L, R;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i < r)
        {
            L.push_back(x);
        }
        if (i >= l)
        {
            R.push_back(x);
        }
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    i64 ans1 = accumulate(L.begin(), L.begin() + r - l, 0LL);
    i64 ans2 = accumulate(R.begin(), R.begin() + r - l, 0LL);
    cout << min(ans1, ans2) << endl;
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

// 不带T
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005
void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<i64> pre(n + 1);
    for (int i = 0; i < n; ++i)
    {
        pre[i + 1] = pre[i] + a[i];
    }
    multiset<i64> lsum;
    i64 ans = LLONG_MAX;
    for (int r1 = 1; r1 <= n; ++r1)
    {
        // 枚举所有左区间可能的和(r1走到最后时 lsum一定存储了所有左区间可能的和)
        for (int l1 = 0; l1 < r1; ++l1)
            lsum.insert(pre[r1] - pre[l1]);
           
        //通过每个左区间右端点的位置 +1，枚举所有右区间可能的和
        for (int r2 = r1 + 1; r2 <= n; ++r2)
        {
            i64 rsum = pre[r2] - pre[r1];
            if (lsum.empty())
                continue;
            auto it = lsum.lower_bound(rsum);
            //检查上界
            if (it != lsum.end())
            {
                ans=min(ans,abs(rsum-*it));
            }
            //检查下界
            if(it!=lsum.begin())
            {
                ans=min(ans,abs(rsum-*prev(it)));
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}

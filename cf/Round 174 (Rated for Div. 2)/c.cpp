#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int MOD = 998244353;
#define N 200005
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<i64> dp(n, 0); // dp数组，dp[i]表示以i结尾的合法中间结构数目
    int cnt1 = 0;         // 当前遇到的1的总数
    i64 res = 0;          

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1)
        {
            cnt1++; // 记录1的个数
            if (i > 0)
                dp[i] = dp[i - 1]; // 继承之前的状态（1不改变中间结构）
        }
        else if (a[i] == 3)
        {
            if (i > 0)
                dp[i] = dp[i - 1];     // 继承之前的状态
            res = (res + dp[i]) % MOD; // 累加以当前3结尾的合法子序列数目
        }
        else
        { 
            if (i > 0)
                dp[i] = (dp[i - 1] * 2) % MOD; // 扩展已有中间结构（选/不选当前2）
            dp[i] = (dp[i] + cnt1) % MOD;      // 新增由当前2和之前所有1组成的子序列
        }
    }

    cout << res % MOD << endl;
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

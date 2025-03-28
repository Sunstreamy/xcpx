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
    vector<int> ans(n);
    // 根据每一行的信息我们能知道比他小的数有几个  比他大的数有几个，但是问题是信息不统一（下三角区域的“1”代表的是比当前行索引小的） 我们希望把每一行的信息统一为通过这一行的数字能得到有几个数字比他大就行了  因此需要将下三角区域转置
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            if (j < i)
            {
                if (x == '0')
                    sum += 1;
                else
                    sum += 0;
            }
            else
                sum += x - '0';
        }
        ans[sum] = i + 1;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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

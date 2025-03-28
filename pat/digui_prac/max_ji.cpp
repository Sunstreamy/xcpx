#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
int solve(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n;i++)
    {
        for (int j = 1; j < i;j++)
        {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
int solve(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, max(solve(n - i), n - i) * i);
        }
        return ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> f(n + 1, 0);
    vector<bool> canstep(n + 1, true);
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        canstep[x] = false;
    }
    f[0] = 1;
    if (canstep[1])
        f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!canstep[i])
            continue; // 不能踩的台阶直接跳过
        f[i] = (f[i - 1] + f[i - 2]) % M;
    }
    cout << f[n] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}

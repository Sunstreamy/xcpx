#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int M = 1e9 + 7;
#define N 200005

int n, m;
i64 ans = LLONG_MAX;
vector<vector<pair<int, i64>>> g;

void solve(int u, i64 cur, vector<bool> &vis)
{
    if (u == n)
    {
        if (cur < ans)
            ans = cur;
        return;
    }
    for (auto &edge : g[u])
    {
        int v = edge.first;
        i64 w = edge.second;
        if (!vis[v])
        {
            vis[v] = true; // 标记节点 v 为已访问
            solve(v, cur ^ w, vis);
            vis[v] = false; // 回溯，取消标记
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        i64 w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<bool> vis(n + 1, false);
    vis[1] = true; // 初始节点 1 已访问
    solve(1, 0, vis);
    cout << ans << endl;
    return 0;
}

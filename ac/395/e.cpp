#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X;
    cin >> N >> M >> X;

    // 修正邻接表结构：每个模式是一个二维数组，original[0]为正常边，original[1]为反转边
    vector<vector<int>> original[2];
    original[0].resize(N + 1);
    original[1].resize(N + 1);

    // 构建邻接表
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        original[0][u].push_back(v); // 正常模式下的边u->v
        original[1][v].push_back(u); // 反转模式下的边v->u（原边反向）
    }

    // 距离数组：dist[顶点][模式]
    vector<vector<ll>> dist(N + 1, vector<ll>(2, INF));
    using State = pair<ll, pair<int, int>>; // (总成本, (顶点, 模式))
    priority_queue<State, vector<State>, greater<State>> pq;

    // 初始化：起点为顶点1，正常模式，成本0
    dist[1][0] = 0;
    pq.push({0, {1, 0}});

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        auto [v, mode] = node;
        pq.pop();

        // 已存在更优路径，跳过
        if (cost > dist[v][mode])
            continue;

        // 到达终点，输出最小成本
        if (v == N)
        {
            cout << min(dist[N][0], dist[N][1]) << endl;
            return 0;
        }

        // 操作1：沿当前模式的边移动
        for (int u : original[mode][v])
        {
            if (dist[u][mode] > cost + 1)
            {
                dist[u][mode] = cost + 1;
                pq.push({dist[u][mode], {u, mode}});
            }
        }

        // 操作2：切换边模式（反转所有边）
        int new_mode = 1 - mode;
        if (dist[v][new_mode] > cost + X)
        {
            dist[v][new_mode] = cost + X;
            pq.push({dist[v][new_mode], {v, new_mode}});
        }
    }

    // 根据题意保证可达，此处防御性返回
    return 0;
}

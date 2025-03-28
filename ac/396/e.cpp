#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent, rank, xor_val;
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        xor_val.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int u, int &x)
    {
        int root = u;
        x = 0;
        while (parent[root] != root)
        {
            x ^= xor_val[root];
            root = parent[root];
        }
        int current_xor = x;
        while (parent[u] != root)
        {
            int next_parent = parent[u];
            int next_xor = xor_val[u];
            parent[u] = root;
            xor_val[u] = current_xor;
            current_xor ^= next_xor;
            u = next_parent;
        }
        return root;
    }

    bool unite(int u, int v, int z)
    {
        int x, y;
        int ru = find(u, x);
        int rv = find(v, y);
        if (ru == rv)
            return (x ^ y) == z;
        if (rank[ru] < rank[rv])
        {
            swap(ru, rv);
            swap(u, v);
            swap(x, y);
        }
        parent[rv] = ru;
        xor_val[rv] = x ^ y ^ z;
        if (rank[ru] == rank[rv])
            rank[ru]++;
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    DSU dsu(N);
    bool possible = true;
    for (int i = 0; i < M; ++i)
    {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        if (!dsu.unite(X, Y, Z))
            possible = false;
    }
    if (!possible)
    {
        cout << -1 << "\n";
        return 0;
    }

    // 对每个节点计算其连通块根和从该根到节点的 xor 值
    vector<int> comp_id(N + 1), node_xor(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        int x;
        int r = dsu.find(i, x);
        comp_id[i] = r;
        node_xor[i] = x;
    }

    // 将各个节点根据其连通块归类
    unordered_map<int, vector<int>> comp_xors;
    for (int i = 1; i <= N; ++i)
    {
        comp_xors[comp_id[i]].push_back(node_xor[i]);
    }

    // 对每个连通块计算最佳基准值，使得整体贡献最小
    unordered_map<int, int> comp_best;
    for (auto &entry : comp_xors)
    {
        int comp = entry.first;
        const vector<int> &vals = entry.second;
        int sz = vals.size();
        int best = 0;
        for (int bit = 30; bit >= 0; --bit)
        {
            int cnt = 0;
            for (int v : vals)
                if (v & (1 << bit))
                    cnt++;
            // 如果本位置1能减少贡献，则在基准值中置1
            if (cnt > (sz - cnt))
                best |= (1 << bit);
        }
        comp_best[comp] = best;
    }

    vector<int> ans(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        int base = comp_best[comp_id[i]];
        ans[i] = base ^ node_xor[i];
    }

    for (int i = 1; i <= N; ++i)
        cout << ans[i] << (i == N ? "\n" : " ");

    return 0;
}
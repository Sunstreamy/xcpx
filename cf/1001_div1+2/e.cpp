#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
    }
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // 构建树结构
    vector<int> parent(n + 1, 0);
    vector<vector<int>> children(n + 1);
    {
        queue<int> q;
        vector<bool> visited(n + 1, false);
        q.push(1);
        visited[1] = true;
        parent[1] = -1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    children[u].push_back(v);
                    q.push(v);
                }
            }
        }
    }
    
    // 计算进入和离开时间
    vector<int> enter(n + 1, 0);
    vector<int> leave(n + 1, 0);
    int time = 0;
    {
        stack<pair<int, bool>> stk;
        stk.push({1, false});
        while (!stk.empty()) {
            auto [node, visited] = stk.top();
            stk.pop();
            if (visited) {
                leave[node] = time++;
            } else {
                enter[node] = ++time;
                stk.push({node, true});
                for (auto it = children[node].rbegin(); it != children[node].rend(); ++it) {
                    stk.push({*it, false});
                }
            }
        }
    }
    
    // 计算子树最大值
    vector<int> max_subtree(n + 1, 0);
    {
        stack<pair<int, bool>> stk;
        stk.push({1, false});
        vector<bool> processed(n + 1, false);
        vector<int> post_order;
        while (!stk.empty()) {
            auto [node, is_processed] = stk.top();
            stk.pop();
            if (is_processed) {
                post_order.push_back(node);
                int current_max = w[node];
                for (int child : children[node]) {
                    if (max_subtree[child] > current_max) {
                        current_max = max_subtree[child];
                    }
                }
                max_subtree[node] = current_max;
            } else {
                if (processed[node]) continue;
                processed[node] = true;
                stk.push({node, true});
                for (auto it = children[node].rbegin(); it != children[node].rend(); ++it) {
                    stk.push({*it, false});
                }
            }
        }
    }
    
    // 计算子树外最大值
    vector<int> max_subtree_out(n + 1, 0);
    {
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            vector<int>& ch = children[p];
            int m = ch.size();
            if (m == 0) continue;
            
            vector<int> prefix_max(m + 1, 0);
            for (int i = 0; i < m; ++i) {
                prefix_max[i + 1] = max(prefix_max[i], max_subtree[ch[i]]);
            }
            
            vector<int> suffix_max(m + 2, 0);
            for (int i = m - 1; i >= 0; --i) {
                suffix_max[i] = max(suffix_max[i + 1], max_subtree[ch[i]]);
            }
            
            for (int i = 0; i < m; ++i) {
                int u = ch[i];
                int other_max = max(prefix_max[i], suffix_max[i + 1]);
                int p_max = (p == 1) ? 0 : max_subtree_out[p];
                int candidate = max(w[p], max(p_max, other_max));
                max_subtree_out[u] = candidate;
                q.push(u);
            }
        }
    }
    
    // 建立哈希表
    unordered_map<int, vector<int>> nodes_dict;
    for (int node = 1; node <= n; ++node) {
        int v = w[node];
        if (max_subtree_out[node] <= v) {
            nodes_dict[v].push_back(enter[node]);
        }
    }
    for (auto& [k, vec] : nodes_dict) {
        sort(vec.begin(), vec.end());
    }
    
    // 检查每个节点
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        int current_max_out = max_subtree_out[i];
        if (current_max_out > w[i]) {
            int M_val = current_max_out;
            auto it = nodes_dict.find(M_val);
            if (it == nodes_dict.end() || it->second.empty()) continue;
            const vector<int>& candidates = it->second;
            int e_i = enter[i];
            int l_i = leave[i];
            // 找不在[e_i, l_i)范围内的
            int left = lower_bound(candidates.begin(), candidates.end(), l_i) - candidates.begin();
            int right_count = left;
            if (right_count < candidates.size()) {
                result = i;
                break;
            }
            if (lower_bound(candidates.begin(), candidates.end(), e_i) - candidates.begin() > 0) {
                result = i;
                break;
            }
        }
    }
    printf("%d\n", result);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
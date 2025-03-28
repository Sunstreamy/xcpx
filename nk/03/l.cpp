#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005

using namespace std;

void get_row_col(int v, int &i, int &j)
{
    v--;
    i = 0;
    while ((i + 1) * (i + 2) / 2 <= v)
    {
        i++;
    }
    j = v - i * (i + 1) / 2;
}

int get_number(int i, int j)
{
    return 1 + i * (i + 1) / 2 + j;
}

vector<vector<int>> build_graph(int n)
{
    int num = (n + 1) * (n + 2) / 2;
    vector<vector<int>> gra(num + 1);
    for (int v = 1; v <= num; v++)
    {
        int i, j;
        get_row_col(v, i, j);
        if (j > 0)
            gra[v].push_back(get_number(i, j - 1));
        if (j < i)
            gra[v].push_back(get_number(i, j + 1));
        if (i + 1 <= n)
            gra[v].push_back(get_number(i + 1, j));
        if (i + 1 <= n)
            gra[v].push_back(get_number(i + 1, j + 1));
        if (i - 1 >= 0 && j <= i - 1)
            gra[v].push_back(get_number(i - 1, j));
        if (i - 1 >= 0 && j - 1 >= 0)
            gra[v].push_back(get_number(i - 1, j - 1));
    }
    return gra;
}

vector<int> solve(vector<vector<int>> &gra)
{
    vector<int> path;
    stack<int> st;
    st.push(1);

    while (!st.empty())
    {
        int v = st.top();
        if (!gra[v].empty())
        {
            int u = gra[v].back();
            gra[v].pop_back();
            auto it = find(gra[u].begin(), gra[u].end(), v);
            if (it != gra[u].end())
                gra[u].erase(it);
            st.push(u);
        }
        else
        {
            path.push_back(v);
            st.pop();
        }
    }

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    auto gra = build_graph(n);
    int odd_cnt = 0;
    for (int v = 1; v < gra.size(); ++v)
    {
        if (gra[v].size() % 2 != 0)
            odd_cnt++;
    }
    if (odd_cnt != 0 && odd_cnt != 2)
    {
        cout << "No" << endl;
        return 0;
    }
    vector<int> path = solve(gra);

    cout << "Yes" << endl;
    for (int i = 0; i < path.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << path[i];
    }
    cout << endl;
    return 0;
}
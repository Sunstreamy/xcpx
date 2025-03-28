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
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }

    map<int, bool> flag;

    set<int> colors;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int d = grid[i][j];
            colors.insert(d);
            if (flag[d])
            {
                continue;
            }
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for (int k = 0; k < 4; ++k)
            {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                {
                    if (grid[ni][nj] == d)
                    {
                        flag[d] = true;
                        break;
                    }
                }
            }
        }
    }

    int sum = 0;
    int mx = 0;
    for (int d : colors)
    {
        int k = flag[d] ? 2 : 1;
        sum += k;
        if (k > mx)
        {
            mx = k;
        }
    }

    cout << sum - mx << endl;
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

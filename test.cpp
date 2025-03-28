#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int r, int c)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
    {
        return;
    }
    grid[r][c] = 0;
    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     int _;
    cin >> _;
    while (_--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        int cnt = 0;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (grid[r][c] == 1)
                {
                    cnt++;
                    dfs(grid, r, c);
                }
            }
        }
        cout << cnt << endl;
    }
    // 请在此输入您的代码
    return 0;
}
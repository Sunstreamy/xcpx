#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005
bool check(char board[3][3], char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }
    for (int j = 0; j < 3; ++j)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

void solve()
{
    char grid[3][3];
    int cnt = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'X')
                cnt++;
        }
    }
    if (cnt <= 2)
    {
        cout << "Yes" << endl;
        return;
    }
    // 先把三个待定的点都变成‘x’，再枚举每个位置变成‘o’，如果存在一种情况使得L成功 输出yes 否则no，注意每次枚举完一种‘o'的位置 要还原棋盘
    if (cnt == 3)
    {
        pair<int, int> point[3];
        int idx = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] == 'G')
                {
                    grid[i][j] = 'X';
                    point[idx++] = {i, j};
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            grid[point[i].first][point[i].second] = 'O';
            if (check(grid, 'X'))
            {
                cout << "Yes" << endl;
                return;
            }
            grid[point[i].first][point[i].second] = 'X';
        }
        cout << "No" << endl;
        return;
    }
    if (cnt == 4)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] == 'G')
                {
                    grid[i][j] = 'X';
                }
            }
        }
        if (check(grid, 'X'))
        {
            cout << "Yes" << endl;
            return;
        }
        else
            cout << "No" << endl;
        return;
    }
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

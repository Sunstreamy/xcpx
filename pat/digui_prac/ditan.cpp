#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 3 * 3 * 3 * 3 * 3 * 3 * 3

char a[N][N];
void solve(int n, int x, int y)
{
    if (n == 1)
    {
        a[x][y] == ' ';
    }
    else
    {
        int unit = (int)pow(3.0, n - 2);
        for (int i = x + unit; i < x + 2 * unit; i++)
        {
            for (int j = y + unit; j < y + 2 * unit; j++)
            {
                a[i][j] = 'X';
            }
        }
        solve(n - 1, x, y); // 递归生成周围的子地毯
        solve(n - 1, x, y + unit);
        solve(n - 1, x, y + 2 * unit);
        solve(n - 1, x + unit, y);
        solve(n - 1, x + unit, y + 2 * unit);
        solve(n - 1, x + 2 * unit, y);
        solve(n - 1, x + 2 * unit, y + unit);
        solve(n - 1, x + 2 * unit, y + 2 * unit);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    memset(a, ' ', sizeof(a));
    int edge = (int)pow(3.0, n - 1);
    solve(n, 0, 0);
    for (int i = 0; i < edge + 2; i++)
    {
        cout << '+';
    }
    cout << endl;
    for (int i = 0; i < edge; i++)
    {
        cout << '+';
        for (int j = 0; j < edge; j++)
        {
            cout << a[i][j];
        }
        cout << "+\n";
    }
    for (int i = 0; i < edge + 2; i++)
    {
        cout << '+';
    }
    cout << endl;

    return 0;
}

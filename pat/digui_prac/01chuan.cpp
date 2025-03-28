#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005

vector<vector<int>> res;
vector<int> tep;
int n;

void solve(int idx)
{
    if (idx == n)
    {
        res.push_back(tep);
        return;
    }
    else
    {
        tep.push_back(0);
        solve(idx + 1);
        tep.pop_back();
        tep.push_back(1);
        solve(idx + 1);
        tep.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    solve(0);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
        }
        cout << endl;
    }

    return 0;
}

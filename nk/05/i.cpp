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
    if(n==0 && n==m)
    {
        cout << "Yes" << endl;
        return;
    }
    if(n!=0 && m!=0)
    {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;

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

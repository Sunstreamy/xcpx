#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
const int M = 1e9 + 7;
void solve()
{
    i64 x;
    cin >> x;
    char c;
    cin >> c;
    if(c=='*')
    {
        cout << x << " " << 1 << endl;
    }
    if(c=='+')
    {
        cout << 1 << " " << x - 1;
    }
    if(c=='-')
    {
        cout << x + 1 << " " << 1;
    }
    
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

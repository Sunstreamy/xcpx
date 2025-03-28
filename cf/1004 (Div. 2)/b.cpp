#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (freq[i] > 2)
        {
            freq[i + 1] += freq[i] - 2;
            freq[i] = 2;
        }
        if (freq[i] == 1)
        {
            cout << "No" << endl;
            return;
        }
    }
     cout << "Yes" << endl;
    return;
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

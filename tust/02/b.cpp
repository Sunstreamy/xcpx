#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
int check(int n)
{
    int power = -1;
    while (n > 0)
    {
        n >>= 1;
        power++;
    }
    return power;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr.begin(), arr.end());
    int tar = arr[0], cnt = 0, pos = 0;
    while (pos < arr.size())
    {
        if (arr[pos] == tar)
        {
            pos++;
        }
        else
        {
            cnt++;
            pos <<= 1;
        }
    }
    cout << cnt << endl;
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

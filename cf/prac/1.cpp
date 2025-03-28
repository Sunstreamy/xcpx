#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005

void solve()
{
    int n;
    cin >> n;
    vector<i64> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> s;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            s.push_back(arr[i]);
            i++;
        }
    }
    if (s.empty())
    {
        cout << -1 << endl;
        return;
    }
    if (s.size() >= 2)
    {
        cout << s[0] << " " << s[0] << " " << s[1] << " " << s[1] << endl;
        return;
    }
    auto it = lower_bound(arr.begin(), arr.end(), s[0]);
    arr.erase(it, it + 2);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] - arr[i] < 2 * s[0])
        {
            cout << s[0] << " " << s[0] << " " << arr[i] << " " << arr[i + 1] << endl;
            return;
        }
    }
    cout << -1 << endl;
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
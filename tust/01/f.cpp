#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
void solve()
{
    string s;
    cin >> s;
    map<char, char> mp = {
        {'A', 'A'},
        {'H', 'H'},
        {'I', 'I'},
        {'M', 'M'},
        {'O', 'O'},
        {'T', 'T'},
        {'U', 'U'},
        {'V', 'V'},
        {'W', 'W'},
        {'X', 'X'},
        {'Y', 'Y'},
        {'b', 'd'},
        {'d', 'b'},
        {'p', 'q'},
        {'q', 'p'},
        {'o', 'o'},
        {'v', 'v'},
        {'w', 'w'},
        {'x', 'x'}};
    bool flag = true;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        char c1 = s[i];
        char c2 = s[n - 1 - i];
        if (mp.find(c1) == mp.end() || mp[c1] != c2)
        {
            flag = false;   
            break;
        }
    }

    if (n % 2 == 1)
    {
        char mid = s[n / 2];
        if (mp.find(mid) == mp.end() || mp[mid] != mid)
        {
            flag = false;
        }
    }
    cout << (flag ? "TAK" : "NIE") << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

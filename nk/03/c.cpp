#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> words(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    sort(words.begin(), words.end());

    i64 sum = 0;
    int max_len = 0;
    for (auto &s : words)
    {
        sum += s.size();
        if (s.size() > max_len)
        {
            max_len = s.size();
        }
    }

    i64 have = 0;
    for (int i = 1; i < words.size(); ++i)
    {
        string a = words[i - 1];
        string b = words[i];
        int lcp = 0;
        while (lcp < a.size() && lcp < b.size() && a[lcp] == b[lcp])
        {
            lcp++;
        }
        have += lcp;
    }

    i64 ans = 2 * sum - max_len - 2 * have;
    cout << ans << endl;

    return 0;
}
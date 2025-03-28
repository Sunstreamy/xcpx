#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<i64> l, r;

    for (int i = 0; i < n; ++i)
    {
        i64 p, v;
        cin >> p >> v;
        if (v == 1)
        {
            r.push_back(p);
        }
        else
        {
            l.push_back(p);
        }
    }

    sort(r.begin(), r.end());
    sort(l.begin(), l.end());

    if (r.empty() || l.empty())
    {
        cout << "No" << endl;
        return 0;
    }

    i64 min_r = r[0];
    i64 max_l = l.back();

    if (max_l <= min_r)
    {
        cout << "No\n";
        return 0;
    }

    i64 sum = 0;
    for (auto r : r)
    {
        auto it = upper_bound(l.begin(), l.end(), r);
        sum += l.end() - it;
    }

    if (sum < k)
    {
        cout << "No" << endl;
        return 0;
    }

    double low = 0.0, high = (max_l - min_r) / 2.0;
    const int iterations = 100;

    for (int i = 0; i < iterations; ++i)
    {
        double mid = (low + high) / 2.0;
        i64 cnt = 0;

        for (auto r : r)
        {// 
            double upper_bound_pos = r + 2 * mid;
            auto start = upper_bound(l.begin(), l.end(), r);
            auto end = upper_bound(l.begin(), l.end(), upper_bound_pos);
            cnt += (end - start);
        }

        if (cnt >= k)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    cout << "Yes" << endl;
    cout << fixed << setprecision(6) << high << endl;

    return 0;
}
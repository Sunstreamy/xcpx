// 不带T
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
const int M = 1e9 + 7;
#define N 200005

stack<int> st;
vector<int> ans;
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < 100; i++)
    {
        st.push(0);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int card;
            cin >> card;
            st.push(card);
        }
        if (x == 2)
        {
            ans.push_back(st.top());
            st.pop();
        }
    }
    for (auto i : ans)
    {
        cout << i << '\n';
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

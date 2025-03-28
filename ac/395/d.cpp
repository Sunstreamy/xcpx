#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> pos(N + 1);
    vector<int> rev(N + 1);
    vector<int> C(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        pos[i] = i;
        rev[i] = i;
        C[i] = i;
    }

    while (Q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b;
            cin >> a >> b;
            pos[a] = rev[b];
        }
        else if (op == 2)
        {
            int a, b;
            cin >> a >> b;
            swap(rev[a], rev[b]);
            C[rev[a]] = a;
            C[rev[b]] = b;
        }
        else
        {
            int a;
            cin >> a;
            cout << C[pos[a]] << endl;
        }
    }

    return 0;
}

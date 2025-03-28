#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005
const int M = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);  
    for (int i = 0;i<n;i++){
        cin >> a[i];
    }

    for (int i = 1;i<n;i++){
        if(a[i]<=a[i-1]){
            cout << "No" << endl;
            return;
        }
    }
    cout<< "Yes" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

    #include <bits/stdc++.h>
    using namespace std;
    typedef long long i64;
    typedef __int128_t i128;
    #define N 200005
    const int M = 1e9 + 7;
    void solve() {
        int n;
        cin >> n;
        
        vector<vector<char>> grid(n, vector<char>(n, '_'));
        
        for (int i = 1; i <= n; ++i) {
            int j = n + 1 - i;
            
            if (i <= j) {
                char color = (i % 2 == 1) ? '#' : '.';  
                for (int row = i - 1; row < j; ++row) {
                    for (int col = i - 1; col < j; ++col) {
                        grid[row][col] = color;  
                    }
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j];
            }
            cout << endl;
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

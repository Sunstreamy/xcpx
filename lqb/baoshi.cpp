#include <bits/stdc++.h>
using namespace std;

const int MAXV = 100000;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++){
        cin >> H[i];
    }
    
    // 构造频次数组
    vector<int> freq(MAXV + 1, 0);
    for (int x : H){
        freq[x]++;
    }
    
    // 枚举 d 从 MAXV 到 1，统计它的倍数个数
    int best = -1;
    for (int d = MAXV; d >= 1; d--){
        int cnt = 0;
        for (int j = d; j <= MAXV; j += d){
            cnt += freq[j];
            if(cnt >= 3) break;
        }
        if(cnt >= 3){
            best = d;
            break;
        }
    }
    
    // best 为最大可能的 gcd，即最大 S
    // 从所有宝石中选择能被 best 整除的三个数，且选字典序最小的方案（排序后取最小3个）
    vector<int> cand;
    for (int x : H){
        if(x % best == 0)
            cand.push_back(x);
    }
    sort(cand.begin(), cand.end());
    // 保证 cand 的元素个数至少有3个（题目保证N>=3，总能选到至少三个数, gcd=1一定可行）
    vector<int> ans = { cand[0], cand[1], cand[2] };
    sort(ans.begin(), ans.end());
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    
    return 0;
}
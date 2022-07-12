#include <bits/stdc++.h>
using namespace std;

// const int N = 1e6;
const long long MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve(){
    int n, s; cin >> n >> s;
    vector<int> coins(n);
    for(int &x : coins) cin >> x;

    vector<vector<int>> dp(n+1,vector<int>(s+1,0)); // dp state that defines, given sum s, how many unique ways possible to get a sum with the given coins
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= s; j++){
            dp[i][j] = dp[i-1][j]; // excluding current coin
            if(j - coins[i-1] >= 0){ // using 0 based indexing
                dp[i][j] += dp[i][j-coins[i-1]]; // including current coin
                // provided that difference is >= 0
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][s] ;
}

int main() {
    solve();
    return 0;
}
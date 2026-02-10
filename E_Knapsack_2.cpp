#include <bits/stdc++.h>
using namespace std;

// const ll MOD = 1e9 + 7;
// const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    long long n, w;
    cin >> n >> w;
    vector<long long> wei(n), val(n);
    for(int i = 0; i < n; i++){
        cin >> wei[i] >> val[i];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(w + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= w; j++){
            if(wei[i - 1] <= j){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wei[i - 1]] + val[i - 1]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}
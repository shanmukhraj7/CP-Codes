# include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
    dp[0][0] = 1.0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            dp[i + 1][j] += dp[i][j] * (1 - a[i]);
            dp[i + 1][j + 1] += dp[i][j] * a[i];
        }
    }
    double ans = 0.0;
    for(int j = (n + 1) / 2; j <= n; j++){
        ans += dp[n][j];
    }
    cout << fixed << setprecision(10) << ans << endl;
}
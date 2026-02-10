#include <bits/stdc++.h>
using namespace std;

# define ll long long

// const ll MOD = 1e9 + 7;
// const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    string s, t;
    cin >> s >> t;
    ll n = s.length(), m = t.length();
    vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string res;
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s[i - 1] == t[j - 1]){
            res.push_back(s[i - 1]);
            i--;
            j--;
        }
        else if(dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}
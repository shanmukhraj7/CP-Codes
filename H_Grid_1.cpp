#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
// const ll INF = 1e18;

# define ll long long

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    if(a[0][0] == '#' || a[n - 1][m - 1] == '#') {
        cout << -1 << endl;
        return;
    }
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    for(int i = 0; i < n; i++){
        if(a[i][0] == '.')
            dp[i][0] = 1;
        else
            break;
    }
    for(int j = 0; j < m; j++){
        if(a[0][j] == '.')
            dp[0][j] = 1;
        else
            break;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(a[i][j] == '.')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            
            }
    }
    cout << (dp[n - 1][m - 1]) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}
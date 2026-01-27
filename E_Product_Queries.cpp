#include <bits/stdc++.h>
using namespace std;

# define ll long long
# define vll vector<ll>

void solve() {
    ll n;
    cin >> n;
    vll a(n), cont(n + 1, 0);
    for(auto& x : a){
        cin >> x;
        cont[x] = 1;
    }
    vll dp(n + 1, LLONG_MAX);
    for(ll i = 1; i <= n; i++){
        if(cont[i]) dp[i] = 1;
    }
    for(ll i = 1; i <= n; i++){
        if(!cont[i]) continue;
        for(ll j = 1; i * j <= n; j++){
            if(dp[j] != LLONG_MAX){
                dp[i * j] = min(dp[i * j], dp[j] + 1);
            }
        }
    }
    for(ll i = 1; i <= n; i++){
        if(dp[i] == LLONG_MAX) cout << -1 << " " ;
        else cout << dp[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
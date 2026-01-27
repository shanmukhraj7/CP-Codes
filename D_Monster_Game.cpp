#include <bits/stdc++.h>
using namespace std;

#define ll long long
# define vll vector<long long>


void solve() {
    ll n;
    cin >> n;
    vll a(n), b(n);
    for(auto& x : a) cin >> x;
    for(auto& x : b) cin >> x;
    sort(a.begin(), a.end(), greater<ll>());
    ll res = 0, s = 0;
    for(ll i = 0; i < n; i++){
        s += b[i];
        if(s > n) break;
        ll gs = a[s - 1] * (i + 1);
        if(gs > res) res = gs;
    }
    cout << res << endl;
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
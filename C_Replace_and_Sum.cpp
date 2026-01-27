#include <bits/stdc++.h>
using namespace std;

#define ll long long
# define vll vector<long long>

void solve() {
    ll n, q;
    cin >> n >> q;
    vll a(n), b(n);
    for(auto& x : a) cin >> x;
    for(auto& y : b) cin >> y;
    vll c(n);
    c[n - 1] = max(a[n - 1], b[n - 1]);
    for(ll i = n - 2; i >= 0; i--){
        c[i] = max(c[i + 1], max(a[i], b[i]));

    }
    vll pfs(n + 1, 0);
    for(ll i = 0; i < n; i++){
        pfs[i + 1] = pfs[i] + c[i];
    }
    for(ll i = 0; i < q; i++){
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << pfs[r + 1] - pfs[l] << " ";
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
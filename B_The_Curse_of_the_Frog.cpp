#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    // write your solution here
    ll n, x;
    cin >> n >> x;
    ll ff = 0, maxv = LLONG_MIN;
    for(int i = 0; i < n; i++){
        ll p, q, r;
        cin >> p >> q >> r;
        ff += (q - 1) * p;
        ll v = p * q - r;
        if(v > maxv) maxv = v;
    }
    if(ff >= x){
        cout << 0 << endl;
        return;
    }
    if(maxv <= 0){
        cout << -1 << endl;
        return;
    }
    ll p1 = x - ff;
    ll res = (p1 + maxv - 1) / maxv;
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
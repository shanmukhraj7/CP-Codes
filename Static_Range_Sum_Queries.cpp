#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SGT{
    vector<ll> seg;
public:
    SGT(int n){
        seg.resize(4 * n);
    }

    void build(ll idx, ll low, ll high, vector<ll>& a){
        if(low == high){
            seg[idx] = a[low];
            return;
        }
        ll mid = low + ((high - low) >> 1);
        build(2 * idx + 1, low, mid, a);
        build(2 * idx + 2, mid + 1, high, a);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    ll query(ll idx, ll low, ll high, ll ql, ll qr){
        if(qr < low || high < ql) return 0;
        if(ql <= low && high <= qr) return seg[idx];
        ll mid = low + ((high - low) >> 1);
        ll left = query(2 * idx + 1, low, mid, ql, qr);
        ll right = query(2 * idx + 2, mid + 1, high, ql, qr);
        return left + right;
    }
};

void solve() {
    // write your solution here
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(auto& x : a) cin >> x;
    SGT sgt(n);
    sgt.build(0, 0, n - 1, a);
    for(int i = 0; i < q; i++){
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << sgt.query(0, 0, n - 1, l, r) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
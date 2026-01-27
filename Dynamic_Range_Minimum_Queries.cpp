#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

class SGT{
    vll seg;
public:
    SGT(int n){
        seg.resize(4 * n + 1);
    }

    void build(ll idx, ll low, ll high, vll& a){
        if(low == high){
            seg[idx] = a[low];
            return;
        }
        ll mid = low + ((high - low) >> 1);
        build(2 * idx + 1, low, mid, a);
        build(2 * idx + 2, mid + 1, high, a);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    ll query(ll idx, ll low, ll high, ll ql, ll qr){
        if(qr < low || high < ql) return LLONG_MAX;
        if(ql <= low && high <= qr) return seg[idx];
        ll mid = low + ((high - low) >> 1);
        ll left = query(2 * idx + 1, low, mid, ql, qr);
        ll right = query(2 * idx + 2, mid + 1, high, ql, qr);
        return min(left, right);
    }

    void update(ll idx, ll low, ll high, ll vi, ll v){
        if(low == high){
            seg[idx] = v;
            return;
        }
        ll mid = low + ((high - low) >> 1);
        if(vi <= mid)
            update(2 * idx + 1, low, mid, vi, v);
        else
            update(2 * idx + 2, mid + 1, high, vi, v);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};

void solve() {
    // write your solution here
    ll n, q;
    cin >> n >> q;
    vll a(n);
    for(auto& x : a) cin >> x;
    SGT sgt(n);
    sgt.build(0, 0, n - 1, a);
    for(int i = 0; i < q; i++){
        ll type;
        cin >> type;
        if(type == 1){
            ll vi, v;
            cin >> vi >> v;
            vi--;
            sgt.update(0, 0, n - 1, vi, v);
        }
        else{
            ll ql, qr;
            cin >> ql >> qr;
            ql--, qr--;
            cout << sgt.query(0, 0, n - 1, ql, qr) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
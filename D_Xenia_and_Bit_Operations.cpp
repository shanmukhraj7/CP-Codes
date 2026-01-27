#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

class SGT {
public:
    vll seg;
    SGT(int n) {
        seg.resize(4 * n);
    }

    void build(ll idx, ll low, ll high, vll &a, ll flag) {
        if (low == high) {
            seg[idx] = a[low];
            return;
        }
        ll mid = low + ((high - low) >> 1);
        build(2 * idx + 1, low, mid, a, !flag);
        build(2 * idx + 2, mid + 1, high, a, !flag);
        if(flag) seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        else seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }

    ll query(ll idx, ll low, ll high, ll start, ll end) {
        if (end < low || high < start) return LLONG_MAX;
        if (start <= low && high <= end) return seg[idx];
        ll mid = low + ((high - low) >> 1);
        ll left = query(2 * idx + 1, low, mid, start, end);
        ll right = query(2 * idx + 2, mid + 1, high, start, end);
        return min(left, right);
    }

    void update(ll idx, ll low, ll high, ll vi, ll v, ll flag) {
        if (low == high) {
            seg[idx] = v;
            return;
        }
        ll mid = low + ((high - low) >> 1);
        if (vi <= mid)
            update(2 * idx + 1, low, mid, vi, v, !flag);
        else
            update(2 * idx + 2, mid + 1, high, vi, v, !flag);
        if(flag)
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        else
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }
};

void solve() {
    // write your solution here
    ll n, m;
    cin >> n >> m;
    ll el = pow(2, n);
    SGT sgt(el);
    vll a(el);
    for(auto& x : a) cin >> x;
    if(n % 2) sgt.build(0, 0, el - 1, a, 1);
    else sgt.build(0, 0, el - 1, a, 0);
    for(ll i = 0; i < m; i++){
        ll p, b;
        cin >> p >> b;
        p--;
        if(n % 2)
            sgt.update(0, 0, el - 1, p, b, 1);
        else
            sgt.update(0, 0, el - 1, p, b, 0);
        cout << sgt.seg[0] << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
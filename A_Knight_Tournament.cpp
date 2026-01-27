#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

class SGT {
private:
    vll seg;
public:
    SGT(int n) {
        seg.resize(4 * n);
    }

    void build(ll idx, ll low, ll high, vll &a) {
        if (low == high) {
            seg[idx] = a[low];
            return;
        }
        ll mid = low + ((high - low) >> 1);
        build(2 * idx + 1, low, mid, a);
        build(2 * idx + 2, mid + 1, high, a);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    ll query(ll idx, ll low, ll high, ll start, ll end) {
        if (end < low || high < start) return LLONG_MAX;
        if (start <= low && high <= end) return seg[idx];
        ll mid = low + ((high - low) >> 1);
        ll left = query(2 * idx + 1, low, mid, start, end);
        ll right = query(2 * idx + 2, mid + 1, high, start, end);
        return min(left, right);
    }

    void update(ll idx, ll low, ll high, ll vi, ll v) {
        if (low == high) {
            seg[idx] = v;
            return;
        }
        ll mid = low + ((high - low) >> 1);
        if (vi <= mid)
            update(2 * idx + 1, low, mid, vi, v);
        else
            update(2 * idx + 2, mid + 1, high, vi, v);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};

void solve() {
    // write your solution here
    
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
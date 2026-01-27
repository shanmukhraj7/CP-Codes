#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

using Node = tuple<ll, ll, ll>;

class SGT {
private:
    vector<Node> seg;
public:
    SGT(int n) {
        seg.resize(4 * n);
    }

    void build(ll idx, ll low, ll high, const string& s) {
        if(low == high){
            if(s[low] == '(')
                seg[idx] = {1, 0, 0};
            else
                seg[idx] = {0, 1, 0};
            return;
        }

        ll mid = low + ((high - low) >> 1);
        build(2 * idx + 1, low, mid, s);
        build(2 * idx + 2, mid + 1, high, s);
        auto [o1, c1, f1] = seg[2 * idx + 1];
        auto [o2, c2, f2] = seg[2 * idx + 2];
        ll f = min(o1, c2);
        seg[idx] = {
            o1 + o2 - f,
            c1 + c2 - f,
            f1 + f2 + f
        };
    }

    Node query(ll idx, ll low, ll high, ll l, ll r){
        if(r < low || high < l) return {0, 0, 0};
        if(l <= low && high <= r) return seg[idx];
        ll mid = low + ((high - low) >> 1);
        Node left = query(2 * idx + 1, low, mid, l, r);
        Node right = query(2 * idx + 2, mid + 1, high, l, r);
        auto [o1, c1, f1] = left;
        auto [o2, c2, f2] = right;
        ll f = min(o1, c2);
        return {
            o1 + o2 - f,
            c1 + c2 - f, 
            f1 + f2 + f
        };
    }

    
};



void solve() {
    // write your solution here
    string str;
    cin >> str;
    ll n = str.size();
    SGT sgt(n);
    sgt.build(0, 0, n - 1, str);
    ll m;
    cin >> m;
    for(int i = 0; i < m; i++){
        ll l, r;
        cin >> l >> r;
        l--, r--;
        auto[o, c, f] = sgt.query(0, 0, n - 1, l, r);
        cout << 2 * f << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
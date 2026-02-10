#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef unordered_map<ll, ll> umll;
typedef unordered_set<ll> usll;
typedef vector<vector<ll>> vvll;

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define lb(v, x) lower_bound((v).begin(), (v).end(), x)
#define ub(v, x) upper_bound((v).begin(), (v).end(), x)
#define sz(x) (ll)((x).size())
#define endl '\n'
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define acc(x) accumulate((x).begin(), (x).end(), 0LL)
#define fori(i, a, b) for(ll i = a; i < b; i++)
#define revi(i, a, b) for(ll i = a; i >= b; i--)
#define forii(i, a, b) for(ll i = a; i <= b; i++)
#define revii(i, a, b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>

void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(string x) { cerr << '"' << x << '"'; }
void _print(char x) { cerr << '\'' << x << '\''; }
void _print(bool x) { cerr << (x ? "true" : "false"); }

template <class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class U> void _print(pair<T, U> p) { cerr << "("; _print(p.ff); cerr << ", "; _print(p.ss); cerr << ")"; }
template <class T> void _print(set<T> s) { cerr << "{ "; for (T i : s) { _print(i); cerr << " "; } cerr << "}"; }
template <class T> void _print(unordered_set<T> s) { cerr << "{ "; for (T i : s) { _print(i); cerr << " "; } cerr << "}"; }
template <class K, class V> void _print(map<K, V> m) { cerr << "{ "; for (auto i : m) { _print(i); cerr << " "; } cerr << "}"; }
template <class K, class V> void _print(unordered_map<K, V> m) { cerr << "{ "; for (auto i : m) { _print(i); cerr << " "; } cerr << "}"; }

// const ll MOD = 1e9 + 7;
// const ll INF = 1e18;
class SGT{
    vll seg, pfs;
public:
    SGT(ll n){
        seg.resize(4 * n + 2);
        pfs.resize(4 * n + 2, 0);
    }

    void build(ll idx, ll low, ll high, vll& a){
        if(low == high){
            seg[idx] = a[low];
            pfs[idx] = max(0LL, a[low]);
            return;
        }
        ll mid = low + ((high - low) >> 1);
        build(2 * idx + 1, low, mid, a);
        build(2 * idx + 2, mid + 1, high, a);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
        pfs[idx] = max(pfs[2 * idx + 1], seg[2 * idx + 1] + pfs[2 * idx + 2]);
    }

    void update(ll idx, ll low, ll high, ll vi, ll v){
        if(low == high){
            seg[idx] = v;
            pfs[idx] = max(0LL, v);
            return;
        }
        ll mid = low + ((high - low) >> 1);
        if(vi <= mid)
            update(2 * idx + 1, low, mid, vi, v); 
        else
            update(2 * idx + 2, mid + 1, high, vi, v);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
        pfs[idx] = max(pfs[2 * idx + 1], seg[2 * idx + 1] + pfs[2 * idx + 2]);
    }

    pll query(ll idx, ll low, ll high, ll ql, ll qr){
        if(qr < low || high < ql) return {0, 0};
        if(ql <= low && high <= qr) return {seg[idx], pfs[idx]};
        ll mid = low + ((high - low) >> 1);
        auto left = query(2 * idx + 1, low, mid, ql, qr);
        auto right = query(2 * idx + 2, mid + 1, high, ql, qr);
        ll total_Sum = left.first + right.first;
        ll max_pfs = max(left.second, left.first + right.second);
        return {total_Sum, max_pfs};
    }
};

void solve() {
    // your code here
    ll n, q;
    cin >> n >> q;
    vll a(n);
    for(auto& x : a) cin >> x;
    SGT sgt(n);
    sgt.build(0, 0, n - 1, a);
    fori(i, 0, q){
        ll type;
        cin >> type;
        if(type == 1){
            ll vi, v;
            cin >> vi >> v;
            vi--;
            sgt.update(0, 0, n - 1, vi, v);
        }
        else{
            ll a, b;
            cin >> a >> b;
            a--, b--;
            cout << sgt.query(0, 0, n - 1, a, b).second << endl;
        }
    }

}

int main() {
    // fast_io();

    // int t;
    // cin >> t;
    // while (t--){
    //    solve();
    // }

    solve();
    return 0;
}
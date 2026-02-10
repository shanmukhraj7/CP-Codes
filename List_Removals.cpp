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
    vll seg;
public:
    SGT(ll n){
        seg.resize(4 * n + 1);
    }

    void build(ll idx, ll low, ll high){
        if(low == high){
            seg[idx] = 1;
            return;
        }
        ll mid = low + ((high - low) >> 1);
        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void update(ll idx, ll low, ll high, ll vi){
        if(low == high){
            seg[idx] = 0;
            return;
        }
        ll mid = low + ((high - low) >> 1);
        if(vi <= mid)
            update(2 * idx + 1, low, mid, vi);
        else
            update(2 * idx + 2, mid + 1, high, vi);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    ll kth(ll idx, ll low, ll high, ll k){
        if(low == high){
            return low;
        }
        ll mid = low + ((high - low) >> 1);
        if(seg[2 * idx + 1] >= k){
            return kth(2 * idx + 1, low, mid, k);
        }
        else{
            return kth(2 * idx + 2, mid + 1, high, k - seg[2 * idx + 1]);
        }
    }
};

void solve() {
    // your code here
    ll n;
    cin >> n;
    vll a(n), b(n);
    for(auto& x : a) cin >> x;
    for(auto& y : b) cin >> y;
    SGT sgt(n);
    sgt.build(0, 0, n - 1);
    fori(i, 0, n){
        ll idx = sgt.kth(0, 0, n - 1, b[i]);
        cout << a[idx] << " ";
        sgt.update(0, 0, n - 1, idx); 
    }
}

int main() {
    fast_io();

    // int t;
    // cin >> t;
    // while (t--){
    //    solve();
    // }

    solve();
    return 0;
}
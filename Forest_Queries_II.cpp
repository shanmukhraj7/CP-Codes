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


void solve() {
    // your code here
    ll n, q;
    cin >> n >> q;
    vector<vector<char>> a(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vvll b(n, vector<ll>(n));
    vvll seg(n + 1, vll(n + 1, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            b[i][j] = (a[i][j] == '*');
        }
    }
    function<void(ll, ll, ll)> update = [&] (ll x, ll y, ll v){
        for(int i = x; i <= n; i += i & -i){
            for(int j = y; j <= n; j += j & -j){
                seg[i][j] += v;
            }
        }
    };
    function<ll(ll, ll)> query = [&] (ll x, ll y)->ll{
        ll res = 0;
        for(int i = x; i > 0; i -= i & -i){
            for(int j = y; j > 0; j -= j & -j){
                res += seg[i][j];
            }
        }
        return res;
    };
    function<ll(ll, ll, ll, ll)> calc = [&] (ll x1, ll y1, ll x2, ll y2)->ll{
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(b[i][j])
                update(i + 1, j + 1, 1);
        }
    }
    fori(i, 0, q){
        ll type;
        cin >> type;
        if(type == 1){
            ll x, y;
            cin >> x >> y;
            if(b[x - 1][y - 1]){
                b[x - 1][y - 1] ^= 1;
                update(x, y, -1);
            }
            else if(!b[x - 1][y - 1]){
                b[x - 1][y - 1] ^= 1;
                update(x, y, 1);
            }
        }
        else{
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << calc(x1, y1, x2, y2) << endl;
        }
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
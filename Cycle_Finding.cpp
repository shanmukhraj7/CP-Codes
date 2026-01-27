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
const ll INF = 1e18;

void solve() {
    // your code here
    ll n, m;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> edges;
    fori(i, 0, m){
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.pb({u, v, wt});
    }
    vll dist(n + 1, 0);
    vll par(n + 1, -1);
    ll x = -1;
    forii(i, 1, n){
        x = -1;
        for(auto& e : edges){
            ll u, v, wt;
            tie(u, v, wt) = e;
            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                par[v] = u;
                x = v;
            }
        }
    }
    if(x == -1){
        cout << "NO" << endl;
        return;
    }
    forii(i, 1, n) x = par[x];
    vll res;
    ll ans = x;
    do{
        res.pb(ans);
        ans = par[ans];
    }while(ans != x);
    res.pb(x);
    reverse(all(res));
    cout << "YES" << endl;
    for(auto& v : res) cout << v << " ";
    cout << endl;
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
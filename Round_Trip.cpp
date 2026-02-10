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

vvll adj;
vll par, v;
ll cs = -1, ce = -1;

bool dfs(ll u, ll p){
    v[u] = 1;
    for(auto nbr : adj[u]){
        if(nbr == p) continue;
        if(!v[nbr]){
            par[nbr] = u;
            if (dfs(nbr, u))
                return true;
        }
        else {
            cs = nbr, ce = u;
            return true;
        }
    }
    return false;
}
void solve() {
    // your code here
    ll n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    forii(i, 1, m){
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    par.resize(n + 1, -1);
    v.resize(n + 1, 0);
    forii(i, 1, n){
        if(!v[i]){
            if(dfs(i, -1))
                break;
        }
    }
    if(cs == -1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vll c;
    c.pb(cs);
    for(ll i = ce; i != cs; i = par[i]){
        c.pb(i);
    }
    c.pb(cs);
    reverse(all(c));
    cout << c.size() << endl;
    for(auto& x : c)
        cout << x << " ";
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
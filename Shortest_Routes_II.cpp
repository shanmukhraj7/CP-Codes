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
const ll INF = 1e18;

void solve() {
    // your code here
    ll n, m, q;
    cin >> n >> m >> q;
    vvll a(n + 1, vll(n + 1, INF));
    forii(i, 1, n) a[i][i] = 0;
    forii(i, 1, m){
        ll u, v, w;
        cin >> u >> v >> w;
        a[u][v] = min(a[u][v], w);
        a[v][u] = min(a[v][u], w);
    }
    forii(k, 1, n){
        forii(i, 1, n){
            forii(j, 1, n){
                if(a[i][k] + a[j][k] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }
    fori(i, 0, q){
        ll u, v;
        cin >> u >> v;
        if(a[u][v] == INF) cout << -1 << endl;
        else cout << a[u][v] << endl;
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
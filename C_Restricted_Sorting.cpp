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
    ll n;
    cin >> n;
    vll a(n);
    fori(i, 0, n) cin >> a[i];
    vll b = a;
    sort(all(b));
    ll u = 2e9, v = -2e9;
    fori(i, 0, n){
        if(a[i] < u) u = a[i];
        if(a[i] > v) v = a[i];
    }
    ll check = 1;
    fori(i, 0, n - 1){
        if(a[i] > a[i + 1]){
            check = 0;
            break;
        } 
    }
    if(check){
        cout << -1 << endl;
        return;
    }
    ll l = 1, r = 1e9, k = 1;
    while(l <= r){
        ll m = l + ((r - l) >> 1);
        ll v1 = v - m, v2 = u + m;
        bool flag = true;
        if(u < v){
            fori(i, 0, n){
                if(a[i] > v1 && a[i] < v2 && a[i] != b[i]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            k = m;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    cout << k << endl;
}

int main() {
    fast_io();

    int t;
    cin >> t;
    while (t--){
       solve();
    }

    // solve();
    return 0;
}
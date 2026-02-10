#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef unordered_map<ll, ll> umll;
typedef unordered_set<ll> usll;
typedef vector<vector<ll>> vvll;

// #define pb push_back
// #define ff first
// #define ss second
// #define all(x) (x).begin(), (x).end()
// #define lb(v, x) lower_bound((v).begin(), (v).end(), x)
// #define ub(v, x) upper_bound((v).begin(), (v).end(), x)
// #define sz(x) (ll)((x).size())
// #define endl '\n'
// #define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define acc(x) accumulate((x).begin(), (x).end(), 0LL)
// #define fori(i, a, b) for(ll i = a; i < b; i++)
// #define revi(i, a, b) for(ll i = a; i >= b; i--)
// #define forii(i, a, b) for(ll i = a; i <= b; i++)
// #define revii(i, a, b) for(ll i = a; i >= b; i--)

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
    string str;
    cin >> str;
    ll nb, ns, nc;
    cin >> nb >> ns >> nc;
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll rubles;
    cin >> rubles;

    // to make x hamburgers -> (xb - nb) * pb, (xs - ns) * ps, (xc - nc) * pc
    ll bc = 0, sc = 0, cc = 0;
    for(char ch : str){
        if(ch == 'B')
            bc++;
        else if(ch == 'S')
            sc++;
        else
            cc++;
    }
    ll low = 0, high = rubles + 100, res = low;
    while(low <= high){
        ll mid = low + ((high - low) >> 1);
        ll reqb = mid * bc;
        ll reqs = mid * sc;
        ll reqc = mid * cc;
        ll amt = rubles;
        amt -= max(0ll, pb * (reqb - nb));
        amt -= max(0ll, ps * (reqs - ns));
        amt -= max(0ll, pc * (reqc - nc));
        if(amt >= 0){
            res = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << res << endl;

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
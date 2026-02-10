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
    ll n, k;
    cin >> n >> k;
    vll a(n);
    fori(i, 0, n) cin >> a[i];
    multiset<ll> st1, st2;
    auto rb = [&](){
        while(st1.size() > st2.size() + 1){
            st2.insert(*prev(st1.end()));
            st1.erase(prev(st1.end()));
        }

        while(st1.size() < st2.size()){
            st1.insert(*st2.begin());
            st2.erase(st2.begin());
        }
    };

    auto add = [&](ll& x){
        if(st1.empty() || x <= *prev(st1.end()))
            st1.insert(x);
        else
            st2.insert(x);
        rb();
    };

    auto rem = [&](ll& x){
        if(st1.find(x) != st1.end())
            st1.erase(st1.find(x));
        else if(st2.find(x) != st2.end())
            st2.erase(st2.find(x));
        rb();
    };

    fori(i, 0, n){
        add(a[i]);
        if(i >= k)
            rem(a[i - k]);
        if(i >= k - 1){
            if(k % 2){
                cout << *prev(st1.end()) << " ";
            }
            else{
                ll x = *prev(st1.end());
                ll y = *st2.begin();
                cout << min(x, y) << " ";
            }
        }
    }
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
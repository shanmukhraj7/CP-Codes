# include <bits/stdc++.h>
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
#define sz(x) (int) ((x).size())
#define endl '\n'
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define acc(x) accumulate((x).begin(), (x).end(), 0LL);

// const ll MOD = 1e9 + 7;
// const ll INF = 1e18;

void solve() {
    // your code here
    ll n, m, k;
    cin >> n >> m >> k;
    vll a(n + 1), a_diff(n + 2, 0), query_diff(m + 2, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<tuple<ll, ll, ll>> qs(m + 1);
    for(int i = 1; i <= m; i++){
        ll l, r, d;
        cin >> l >> r >> d;
        qs[i] = {l, r, d};
    }
    for(int i = 0; i < k; i++){
        ll x, y;
        cin >> x >> y;
        query_diff[x]++;
        query_diff[y + 1]--;
    }
    for(int i = 1; i <= m; i++){
        query_diff[i] += query_diff[i - 1];
    }
    for(int i = 1; i <= m; i++){
        ll rep = query_diff[i];
        auto[l, r, d] = qs[i];
        a_diff[l] += rep * d;
        a_diff[r + 1] -= rep * d;
        
    }  
    for(int i = 1; i <= n; i++){
        a_diff[i] += a_diff[i - 1];
        cout <<  a[i] + a_diff[i] << " ";
    }
    
    
}

int main() {
    fast_io();

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    solve();

    return 0;
}

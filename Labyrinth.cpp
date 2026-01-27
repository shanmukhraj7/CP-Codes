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

void solve() {
    // your code here
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    ll sx = -1, sy = -1, dx = -1, dy = -1;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A')
                sx = i, sy = j;
            else if(grid[i][j] == 'B')
                dx = i, dy = j;
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pll>> par(n, vector<pll>(m));
    vector<vector<char>> move(n, vector<char> (m));
    vector<ll> dirx = {0, 0, -1, 1};
    vector<ll> diry = {-1, 1, 0, 0};
    vector<char> dir = {'L', 'R', 'U', 'D'};
    queue<pll> q;
    q.push({sx, sy});
    while(!q.empty()){
        auto[r, c] = q.front(); q.pop();
        for(ll j = 0; j < dir.size(); j++){
            ll nr = r + dirx[j], nc = c + diry[j];
            char ch = dir[j];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(vis[nr][nc] || grid[nr][nc] == '#') continue;
            vis[nr][nc] = true;
            par[nr][nc] = {r, c};
            move[nr][nc] = ch;
            q.push({nr, nc});
        }
    }
    if(!vis[dx][dy]){
        cout << "NO" << endl;
        return;
    }
    ll x = dx, y = dy;
    string res;
    while(!(x == sx && y == sy)){
        res.pb(move[x][y]);
        auto p = par[x][y];
        x = p.ff, y = p.ss;
    }
    reverse(all(res));
    cout << "YES" << endl;
    cout << res.size() << endl;
    cout << res << endl;
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
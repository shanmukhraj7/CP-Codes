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
    // your code 
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char> (m));
    fori(i, 0, n){
        fori(j, 0, m){
            cin >> a[i][j];
        }
    }
    queue<pll> q1;
    ll sx = -1, sy = -1;
    vvll d1(n, vll(m, INF));
    fori(i, 0, n){
        fori(j, 0, m){
            if(a[i][j] == 'M'){
                q1.push({i, j});
                d1[i][j] = 0;
            }
            else if(a[i][j] == 'A')
                sx = i, sy = j;
        }
    }
    vll dirx = {1, -1, 0, 0}, diry = {0, 0, 1, -1};
    vector<char> dir = {'D', 'U', 'R', 'L'};
    while(!q1.empty()){
        auto[x, y] = q1.front();
        q1.pop();
        for(int i = 0; i < 4; i++){
            ll nx = x + dirx[i], ny = y + diry[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#' && d1[nx][ny] == INF){
                d1[nx][ny] = d1[x][y] + 1;
                q1.push({nx, ny});
            }
        }
    }
    vvll d2(n, vll(m, -1));
    vector<vector<char>> par(n, vector<char>(m));
    queue<pll> q2;
    q2.push({sx, sy});
    d2[sx][sy] = 0;
    while(!q2.empty()){
        auto[x, y] = q2.front(); q2.pop();
        if(x == 0 || x == n - 1 || y == 0 || y == m - 1){
            cout << "YES" << endl;
            string res;
            while(x != sx || y != sy){
                char c = par[x][y];
                res.pb(c);
                if(c == 'D') x--;
                else if(c == 'U') x++;
                else if(c == 'R') y--;
                else if(c == 'L') y++;
            }
            reverse(all(res));
            cout << res.size() << endl;
            cout << res << endl;
            return;
        }
        for(int i = 0; i < 4; i++){
            ll nx = x + dirx[i], ny = y + diry[i];
            char ch = dir[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#' && d2[nx][ny] == -1 && d2[x][y] + 1 < d1[nx][ny]){
                d2[nx][ny] = d2[x][y] + 1;
                par[nx][ny] = ch;
                q2.push({nx, ny});
            }
        }
    }
    cout << "NO" << endl;
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
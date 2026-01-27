#include <bits/stdc++.h>
using namespace std;

#define ll long long
# define pb push_back

class DSU{
public:
    vector<ll> parent, size;

    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findPar(int u){
        if(u == parent[u]) return u;
        return parent[u] = findPar(parent[u]);
    }

    bool  Union(int u, int v, ll& maxv){
        ll pu = findPar(u), pv = findPar(v);
        if(pu == pv) return false;
        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        maxv = max(maxv, size[pu]);
        return  true;
    }

};


void solve() {
    // write your solution here
    ll n, m;
    cin >> n >> m;
    DSU dsu(n);
    ll cnt = n, maxv = 1;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if(dsu.Union(u, v, maxv)){
            cnt--;
        }
        cout << cnt << " " << maxv << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while (t--) {
        solve();
    // }

    return 0;
}
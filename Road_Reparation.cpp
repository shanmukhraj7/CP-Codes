#include <bits/stdc++.h>
using namespace std;

#define ll long long
# define pb push_back

class DSU{
public:
    vector<int> parent, size;

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

    auto  Union(int u, int v){
        int pu = findPar(u), pv = findPar(v);
        if(pu == pv) return false;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pu] = pv;
            size[pu] += size[pv];
        }
        return true;
    }

};


void solve() {
    // write your solution here
    ll n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<vector<ll>> edges;
    for(int i = 0; i < m; i++){
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        edges.pb({u, v, d});
    }
    sort(edges.begin(), edges.end(), [](auto& a, auto& b){
        return a[2] < b[2];
    });


    ll cost = 0;
    for(auto e : edges){
        int u = e[0], v = e[1], d = e[2];
        if(dsu.Union(u, v)) cost += d; 
    }
    unordered_set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(dsu.findPar(i));
    }
    if(st.size() > 1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << cost << endl;
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
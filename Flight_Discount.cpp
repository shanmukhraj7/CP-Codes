#include <bits/stdc++.h>
using namespace std;

typedef tuple<long long, int, int> tii;

// const ll MOD = 1e9 + 7;
const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<pair<long long, long long>>> adjList(vertices + 1);
    for(int i = 0; i < edges; i++){
        int u, v;
        long long w;
        cin >> u >> v;
        cin >> w;
        adjList[u].push_back({v, w});
    }
    vector<vector<long long>> dist(vertices + 1, vector<long long>(2, INF));
    dist[1][0] = 0;
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    pq.push({0, 1, 0}); // dist, node, chance
    while(!pq.empty()){
        auto[weight, node, chance] = pq.top();
        pq.pop();
        if(weight > dist[node][chance]) continue;
        for(auto [adjNode, adjWeight] : adjList[node]){
            if(adjWeight + weight < dist[adjNode][chance]){
                dist[adjNode][chance] = adjWeight + weight;
                pq.push({dist[adjNode][chance], adjNode, chance});
            }
            if(chance == 0 && weight + adjWeight / 2 < dist[adjNode][1]){
                dist[adjNode][1] = weight + adjWeight / 2;
                pq.push({dist[adjNode][1], adjNode, 1});
            }
        }
    }
    cout << dist[vertices][1] << endl;
    return 0;
}
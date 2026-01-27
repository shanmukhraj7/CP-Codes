#include <bits/stdc++.h>
using namespace std;

#define ll long long
# define vll vector<ll>

void solve() {
    ll n, s, x;
    cin >> n >> s >> x;
    vll a(n);
    ll total = 0;
    for(auto& x : a){
        cin >> x;
        total += x;
    }
    if(s >= total && (s - total) % x == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
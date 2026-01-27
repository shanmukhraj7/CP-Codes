#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for(auto& x : a) cin >> x;
    vll sfx(n), pos(n);
    sfx[n - 1] = a[n - 1];
    pos[n - 1] = n - 1;
    for(ll i = n - 2; i >= 0; i--){
        if(a[i] <= sfx[i + 1]){
            sfx[i] = sfx[i + 1];
            pos[i] = pos[i + 1];
        }
        else{
            sfx[i] = a[i];
            pos[i] = i;
        }
    }
    for(ll i = 0; i < n; i++){
        if(sfx[i] > a[i]){
            reverse(a.begin() + i, a.begin() + pos[i] + 1);
            break;
        }
    }
    for(auto x : a) cout << x << " ";
    cout << endl;
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
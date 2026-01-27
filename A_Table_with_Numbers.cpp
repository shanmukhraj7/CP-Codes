#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    // write your solution here
    ll n, h, l;
    cin >> n >> h >> l;
    ll b = 0, r = 0, c = 0;
    for(int i = 0; i < n; i++){
        ll val;
        cin >> val;
        if(val <= h && val <= l) b++;
        else if(val <= h) r++;
        else if(val <= l) c++;
    }
    ll res = min(r, c);
    ll rem = (r + c) - (2 * res);
    ll usage = min(rem, b);
    res += usage;
    b -= usage;
    res += b / 2;
    cout << res << endl;
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
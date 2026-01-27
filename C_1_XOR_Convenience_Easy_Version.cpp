#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        p[n] = 1;
        for (int i = 2; i <= n - 1; i++) p[i] = (i ^ 1);
        p[1] = (n % 2 == 0 ? n : n - 1);
        for (int i = 1; i <= n; i++) {
            cout << p[i] << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}
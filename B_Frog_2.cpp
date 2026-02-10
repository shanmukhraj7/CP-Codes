#include <bits/stdc++.h>
using namespace std;

// const ll MOD = 1e9 + 7;
// const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<int> dp(n, 2e9);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = max(0, i - k); j < i; j++){
            dp[i] = min(dp[i], dp[j] + abs(nums[i] - nums[j]));
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}


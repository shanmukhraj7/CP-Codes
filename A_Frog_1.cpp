#include <bits/stdc++.h>
using namespace std;

// const ll MOD = 1e9 + 7;
// const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(nums[1] - nums[0]);
    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i - 1] + abs(nums[i] - nums[i - 1]), dp[i - 2] + abs(nums[i] - nums[i - 2]));
    }
    cout << dp[n - 1] << endl;
    return 0;
}
# include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    function<int(int)> solve = [&] (int num) -> int{
        if(num == 1){
            return 1;
        }
        cout << num << " ";
        solve(num - 1);
    };
    cout << solve(n) << endl;
    return 0;
}
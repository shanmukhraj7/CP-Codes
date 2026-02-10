# include <bits/stdc++.h>
using namespace std;

void solve(int num){
    if(num == 1){
        cout << num << endl;
        return;
    }
    solve(num - 1);
    cout << num << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}
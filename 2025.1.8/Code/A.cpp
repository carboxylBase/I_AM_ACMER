// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
void solve(){
    ll sum[3];
    for (int i = 0;i<3;i++){
        cin >> sum[i];
    }
    sort(sum,sum+3);
    if (sum[0] + sum[1] == sum[2] || (sum[0] == sum[1] && sum[0] == sum[2])){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return;
}

signed main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _ = 1;
    while (_--){
        solve();
    }
    return 0;
}
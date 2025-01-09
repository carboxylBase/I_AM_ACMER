// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
void solve(){
    ll l,r;
    cin >> l >> r;
    ll cnt = 0;
    for (int i = l;i<r+1;i++){
        if (i % 2 == 0){
            cnt++;
        }
    }
    cout << cnt << endl;
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
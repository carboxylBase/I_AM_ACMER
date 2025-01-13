// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
void solve(){
    ll n;
    cin >> n;
    ll ans = n / 7 * 5 * 3;
    n %= 7;
    if (n > 5){
        n = 5;
    }
    ans += n * 3;
    cout << ans;
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
// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
void solve(){
    ll n,a[3],sum = 0;
    cin >> n;
    for (int i = 0;i<3;i++) cin >> a[i],sum+=a[i];
    ll ans = n / sum * 3;n %= sum;
    for (int i = 0;i<3&&n>0;i++){
        n -= a[i];
        ans++;
    }
    cout << ans << "\n";
    return;
}

signed main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--){
        solve();
    }
    return 0;
}
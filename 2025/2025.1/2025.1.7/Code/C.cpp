// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll MOD = 1e9 + 7;
const ll N = 2000000;
void solve(){
    ll n;
    cin >> n;
    ll sum0 = n / 2;
    ll sum1 = n - sum0;
    ll ans = 1;
    ll res = 1;
    for (int i = 1;i<=sum0;i++){
        res *= (sum0 - i + 1);
        res %= MOD;
    }
    ans = res;
    res = 1;
    for (int i = 1;i<=sum1;i++){
        res *= (sum1 - i + 1);
        res %= MOD;
    }
    ans *= res;
    ans %= MOD;
    if(n%2 == 0) ans *= 2;
    ans %= MOD;
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
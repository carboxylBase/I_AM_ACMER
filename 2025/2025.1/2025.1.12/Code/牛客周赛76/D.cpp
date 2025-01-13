// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;

ll n,k;

__int128 quick(ll base,ll k){
    __int128 res = 1;
    while (k){
        if (k & 1){
            res *= base;
        }
        base *= base;
        k >>= 1;
    }
    return res;
}

void solve(){
    cin >> n >> k;
    if (k == 1){
        cout << n << endl;
        return;
    }
    double m = log2(n);
    ll l = 1,r = sqrt(n),ans,mid;
    while (l<=r){
        mid = l+r>>1;
        double o = log2(mid);
        o *= k;
        if (o <= m){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    } 

    if (quick(ans+1,k) < quick(ans,k)){
        cout << ans << endl;
        return;
    }

    if (n - quick(ans,k) <= quick(ans+1,k) - n){
        cout << ans << endl;
    }else{
        cout << ans + 1 << endl;
    }
    return;
}

signed main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _ = 1;cin >> _;
    while (_--){
        solve();
    }
    return 0;
}
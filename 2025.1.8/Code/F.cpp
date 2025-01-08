// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
int n;
ll x[N];
ll h[N];

void solve(){
    cin >> n;
    for (int i = 1;i<n+1;i++){
        cin >> x[i] >> h[i];
    }
    long double ans = 0;
    bool big0 = 0;
    for (int i = 2;i<=n;i++){
        if (x[i] * h[i-1] - h[i] * x[i-1] >= 0){
            big0 = 1;
        }
        ans = max(ans,(long double)(x[i] * h[i-1] - h[i] * x[i-1]) / (x[i] - x[i-1]));
    }
    if (!big0){
        cout << -1 << endl;
    }else{
        cout << fixed << setprecision(12) << ans << endl;
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
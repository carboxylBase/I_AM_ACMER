// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
void solve(){
    ll n,x,y,sum = 0;
    cin >> n >> x >> y;
    vector<ll> a(n+1);
    for (int i = 1;i<n+1;i++) cin >> a[i],sum+=a[i];
    sort(a.begin(),a.end());
    ll ans = 0;
    for (int i = 1;i<n+1;i++){
        int l = i+1,r = n,L=-1,R=-1;
        while (l<=r){
            int mid = l+r>>1;
            if (sum - a[mid] - a[i] <= y){
                L = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        l = i+1,r = n;
        while (l<=r){
            int mid = l+r>>1;
            if (sum - a[mid] - a[i] >= x){
                R = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        if (L==-1||R==-1){
            continue;
        }else{
            ans += R - L + 1;
        }
    }
    cout << ans << "\n";
    return;
}

signed main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--){
        solve();
    }
    return 0;
}
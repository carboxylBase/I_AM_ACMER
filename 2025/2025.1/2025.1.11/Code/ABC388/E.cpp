// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
ll n,a[N];
bool check(int x){
    for (int i = 0;i<x;i++){
        if (a[n - i] / 2 < a[x - i]){
            return 0;
        }
    }
    return 1;
}
void solve(){
    cin >> n;
    for (int i = 1;i<n+1;i++){
        cin >> a[i];
    }

    int l = 0,r = n / 2;
    int ans = 0,mid;
    while (l<=r){
        mid = l+r>>1;
        if (check(mid)){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
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
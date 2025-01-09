// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    
    for (int i = 0;i<n;i++) cin >> a[i];
    for (int i = 0;i<n;i++) cin >> b[i];

    int ans = a[n-1];
    for (int i = 0;i<n-1;i++){
        if (a[i] > b[i+1]){
            ans += a[i] - b[i+1];
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
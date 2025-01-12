// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
void solve(){
    int n,d;
    cin >> n >> d;
    vector<int> h(n),w(n);
    for (int i = 0;i<n;i++){
        cin >> w[i] >> h[i];
    }
    for (int i = 1;i<=d;i++){
        int ans = 0;
        for (int j = 0;j<n;j++){
            ans = max(ans,(h[j]+i) * w[j]);
        }
        cout << ans << endl;
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
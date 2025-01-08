// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;

int n;
vector<int> g[N];

void solve(){
    cin >> n;
    for (int i = 1;i<n;i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v),g[v].push_back(u);
    }

    ll ans = 0;

    for (int i = 1;i<n+1;i++){
        vector<int> d;
        for (auto v:g[i]){
            d.push_back(g[v].size() - 1);
        }
        sort(d.begin(),d.end());
        for (int j = d.size()-1;j>=0;j--){
            ans = max(ans,ll(1+(d.size() - j) * (d[j] + 1)));
        }
    }

    cout << n - ans << endl;
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
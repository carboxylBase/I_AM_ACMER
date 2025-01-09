// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define DEBUG 1
const ll N = 2000000;

int n,q;
vector<int> g[N];
int colors[N];// 0 red
string s;
int fa[N],dep[N];
void dfs(int u,int f){
    fa[u] = f,dep[u] = dep[f]+1;
    for (auto v:g[u]){
        if (f == v) continue;
        dfs(v,u);
    }
    return;
}

int dp[N][2][2];

int filldp(int u,int i,int j){
    if (dp[u][i][j]!=-1){
        return dp[u][i][j];
    }
    int res = 0;
    if (i == 1 && j == 1){
        dp[u][i][j] = 0;
        res = 1000000000;
        for (auto v:g[u]){
            if (v == fa[u]) continue;
            dp[u][i][j] += filldp(v,0,1);
            res = min(res,filldp(v,1,0) - filldp(v,0,1));
        }
        dp[u][i][j] += res;
        // if (u == 1){
        //     cout << dp[u][i][j] << endl;
        //     cout << res << endl;
        // }
    }else if (i == 1 && j == 0){
        dp[u][i][j] = 0;
        for (auto v:g[u]){
            if (v == fa[u]){
                continue;
            }
            dp[u][i][j] += filldp(v,0,1);
        }
    }else if (i == 0 && j == 1){
        dp[u][i][j] = 0;
        res = 1000000000;
        for (auto v:g[u]){
            if (v == fa[u]) continue;
            dp[u][i][j] += filldp(v,1,1);
            res = min(res,filldp(v,0,0) - filldp(v,1,1));
        }
        dp[u][i][j] += res;
    }else{
        dp[u][i][j] = 0;
        for (auto v:g[u]){
            if (v == fa[u]){
                continue;
            }
            dp[u][i][j] += filldp(v,1,1);
        }
    }
    if (i != colors[u]){
        dp[u][i][j]++;
    }
    return dp[u][i][j];
}

void solve(){
    cin >> n >> q >> s;
    for (int i = 0;i<n;i++){
        colors[i+1] = (s[i] == 'R' ? 0 : 1);
    }
    // for (int i = 1;i<n+1;i++){
    //     cout <<i<<" "<< colors[i]<<endl;
    // }
    // cout << endl;
    for (int i = 0;i<n-1;i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v),g[v].push_back(u);
    }
    for (int i = 1;i<n+1;i++){
        dp[i][0][0] = dp[i][0][1] = dp[i][1][1] = dp[i][1][0] = -1;
    }
    int u,v;
    cin >> u >> v;
    dfs(1,1);
    while (u!=v){
        colors[u] = colors[v] = 0;
        if (dep[u] > dep[v]){
            swap(u,v);
        }
        v = fa[v];
    }

    // for (int i = 1;i<n+1;i++){
    //     cout <<i<<" "<< colors[i]<<endl;
    // }
    // cout << endl;
    ll ans = min(filldp(1,1,1),filldp(1,0,1));
    if (ans >= 1000000000){
        ans = -1;
    }
    cout << ans << endl;

    // for (int i = 1;i<n+1;i++){
    //     cout << i << " " <<  filldp(i,0,0) << " " << filldp(i,0,1) << " " << filldp(i,1,0) << " " << filldp(i,1,1) << endl;
    // }

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
// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 110000;
int n,q;
string s;
int colors[N];
vector<int> g[N];

int dep[N],siz[N],fa[N][32];
// 路径上的蓝色点数目
// 整棵树原本需要的操作次数
// 路径上的操作次数
int blues[N][32][2],ori[2],ans[N][32][2];
int ans_color[N][2];

void dfs_pre(int u,int f){
    siz[u] = 1;
    fa[u][0] = f;
    dep[u] = dep[f] + 1;
    for (auto v:g[u]){
        if (v == f) continue;
        dfs_pre(v,u);
        siz[u] += siz[v];
    }
}

bool wujie = 0;

void dfs_check(int u,int f,bool vis){
    if (vis){
        for (auto v:g[u]){
            if (v == f) continue;
            ans_color[v][0] = 1 - ans_color[u][0];
            dfs_check(v,u,0);
        }
    }else{
        int son,sum = 0;
        for (auto v:g[u]){
            if (f == v) continue;
            if (siz[v]&1){
                son = v;sum++;
            }
        }
        if (sum == 1){
            ans_color[son][0] = ans_color[u][0];
            dfs_check(son,u,1);
            for (auto v:g[u]){
                if (v == f || v == son) continue;
                ans_color[v][0] = 1 - ans_color[u][0];
                dfs_check(v,u,0);
            }
        }else{
            wujie = 1;
            return;
        }
    }
}

void dfs_lca(int u,int f){
    for (int i = 1;i<32;i++){
        fa[u][i] = fa[fa[u][i-1]][i-1];
        for (int j = 0;j<2;j++){
            blues[u][i][j] = blues[u][i-1][j] + blues[fa[u][i-1]][i-1][j];
            ans[u][i][j] = ans[u][i-1][j] + ans[fa[u][i-1]][i-1][j];
        }
    }
    for (auto v:g[u]){
        if (f == v) continue;
        dfs_lca(v,u);
    }
}

void solve(){
    cin >> n >> q >> s;
    for (int i = 0;i<n;i++){
        if (s[i] == 'R'){
            colors[i+1] = 0;
        }else{
            colors[i+1] = 1;
        }
    }
    for (int i = 0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v),g[v].push_back(u);
    }

    dfs_pre(1,0);dfs_check(1,0,0);
    if (wujie){
        while (q--){
            cout << -1 << endl;
        }
        return;
    }
    for (int i = 1;i<n+1;i++){
        ans_color[i][1] = 1 - ans_color[i][0];
        if (ans_color[i][0] != colors[i]){
            ori[0]++;
            ans[i][0][0] = 1;
        }
        if (ans_color[i][1] != colors[i]){
            ori[1]++;
            ans[i][0][1] = 1;
        }
        for (int j = 0;j<2;j++){
            if (ans_color[i][j] == 1){
                blues[i][0][j] = 1;
            }
        }
    }
    // cout << fa[4][1] << endl;
    dfs_lca(1,0);
    // for (int i = 1;i<n+1;i++){
    //     cout << ans[i][0][0] << " ";
    // }
    // cout << endl;
    while (q--){
        // 路径上的蓝色点数目.
        int blueWay[2] = {0,0};
        // 路径上的原本操作数目
        int oriWay[2] = {0,0};
        //下面来lca
        int u,v;
        cin >> u >> v;
        if (dep[u] > dep[v]) swap(u,v);
        int tmp = dep[v] - dep[u];
        for (int i = 0;tmp;i++,tmp>>=1){
            if (tmp & 1) {
                for (int j = 0;j<2;j++){
                    blueWay[j] += blues[v][i][j];
                    oriWay[j] += ans[v][i][j];
                }
                v = fa[v][i];
            }
        }
        if (u == v){
            for (int i = 0;i<2;i++){
                blueWay[i] += blues[u][0][i];
                oriWay[i] += ans[u][0][i];
            }
        }else{
            for (int i = 30;i>-1;i--){
                if (fa[u][i] != fa[v][i]){
                    for (int j = 0;j<2;j++){
                        blueWay[j] += blues[u][i][j];
                        oriWay[j] += ans[u][i][j];
                        blueWay[j] += blues[v][i][j];
                        oriWay[j] += ans[v][i][j];
                    }
                    u = fa[u][i],v = fa[v][i];
                }
            }
            for (int j = 0;j<2;j++){
                blueWay[j] += blues[u][0][j]+blues[v][0][j]+blues[fa[u][0]][0][j];
                oriWay[j] += ans[u][0][j]+ans[v][0][j]+ans[fa[u][0]][0][j];
            }
            u = fa[u][0];
        }

        int ANS[2] = {0,0};
        ANS[1] = blueWay[1] + ori[1] - oriWay[1];//BBRR
        ANS[0] = blueWay[0] + ori[0] - oriWay[0];//RRBB
        // cout << ori[1] << " " << ori[0] << endl;
        // cout << blueWay[1] << ' ' << blueWay[0] << endl;
        // cout << oriWay[1] << " " << oriWay[0] << endl;
        cout << min(ANS[1],ANS[0]) << endl;
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
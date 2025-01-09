// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define DEBUG 1
const ll N = 200000;
int n,C,m;
int a[N],b[N];
bool vis[N];
struct Node{
    int cost,value,siz;
    Node(int A = 0,int B = 0,int C = 0){
        cost = A,value = B;
        siz = C;
    }
};
vector<vector<Node>> nodes;
int dp[N][10];

void solve(){
    cin >> n >> C >> m;
    for (int i = 1;i<n+1;i++) cin >> a[i] >> b[i];
    for (int i = 1;i<m+1;i++){
        int u,v,w;
        cin >> u >> v >> w;
        vis[u] = vis[v] = 1;
        vector<Node> q;
        q.push_back(Node(a[u],b[u],1));
        q.push_back(Node(a[v],b[v],1));
        q.push_back(Node(a[u]+a[v],b[u]+b[v]+w,2));
        nodes.push_back(q);
    }
    for (int i = 1;i<n+1;i++){
        if (!vis[i]){
            vector<Node> q;
            q.push_back(Node(a[i],b[i],1));
            nodes.push_back(q);
        }
    }
    for (int i = 0;i<nodes.size();i++){
        for (int j = C;j>=0;j--){
            for (int o = 0;o<=4;o++){
                for (int k = 0;k<nodes[i].size();k++){
                    if (j-nodes[i][k].cost<0||o-nodes[i][k].siz<0) continue;
                    dp[j][o] = max(dp[j][o],dp[j-nodes[i][k].cost][o-nodes[i][k].siz]+nodes[i][k].value);
                }
            }
        }
    }
    cout << dp[C][4] << endl;
    return;
}

signed main(){
  //  freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _ = 1;
    while (_--){
        solve();
    }
    return 0;
}
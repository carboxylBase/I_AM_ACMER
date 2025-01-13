// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
#define int ll
const ll N = 2000000;

class shortestPath{
    #define N 2000000
    struct Edge  
    {
        int v, w, next;
    };
    struct Node
    {
        int dis, id;
        bool operator<(const Node &a) const { return dis > a.dis; }
        Node(int d, int x) { dis = d, id = x; };
    };
    public:
        ll n;
        ll cnt = 0; 
        ll head[N];
        Edge edges[N];
        bool vis[N];
        ll dist[N];
        ll t[N];
    public:
        void add(ll u, ll v, ll w)
        {
            edges[++cnt].next = head[u];
            head[u] = cnt;
            edges[cnt].v = v;
            edges[cnt].w = w;
            return;
        }
        void dijkstra(ll pos)
        {
            priority_queue<Node> q;
            for (ll i = 1; i < n + 1; i++)
            {
                dist[i] = 0x3f3f3f3f3f3f;
            }
            memset(vis, 0, sizeof vis);
            dist[pos] = 0;
            q.push(Node(0, pos));
            while (!q.empty())
            {
                ll u = q.top().id;
                q.pop();
                if (vis[u])
                {
                    continue;
                }
                vis[u] = 1;
                for (ll i = head[u]; i; i = edges[i].next)
                {
                    ll v = edges[i].v;
                    if (dist[v] > dist[u] + edges[i].w)
                    {
                        dist[v] = dist[u] + edges[i].w;
                        if (!vis[v])
                        {
                            q.push(Node(dist[v], v));
                        }
                    }
                }
            }
            return;
        }
        //false means negative loop.
        bool spfa(int pos)
        {
            queue<int> q;
            memset(dist, 0x3f3f3f3f3f3f, sizeof dist);
            dist[pos] = 0, vis[pos] = 1;
            q.push(pos);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                vis[u] = 0;
                for (int i = head[u]; i; i = edges[i].next)
                {
                    int v = edges[i].v;
                    if (dist[v] > dist[u] + edges[i].w)
                    {
                        dist[v] = dist[u] + edges[i].w;
                        if (!vis[v])
                        {
                            vis[v] = 1;
                            q.push(v);
                            t[v]++;
                            if (t[v] == n + 1)
                            {
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }
};

struct Node
{
    int pos;
    ll dist;
    Node(int P = 0,ll D = 0){
        pos = P,dist = D;
    }
    bool operator<(const Node& A) const{
        return dist > A.dist;
    }
};
priority_queue<Node> q;


int U[N],V[N];
bool vis[N];
void solve(){
    shortestPath solver;
    int n,m;
    cin >> n >> m;
    for (int i = 1;i<m+1;i++){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        U[i] = u,V[i] = v;
        solver.add(u,v,w);
        solver.add(v,u,w);
    }

    solver.n = n;

    solver.dijkstra(n);
    map<pair<int,int>,bool> ans;
    q.push(Node(1,0));
    vis[1] = 1;

    if (solver.dist[1] == 0x3f3f3f3f3f3f){
        for (int i = 1;i<m+1;i++){
            cout << "Yes\n";
        }
        return;
    }

    // for (int i = 1;i<n+1;i++){
    //     cout << i << " " << solver.dist[i] << endl;
    // }
    while (!q.empty()){
        int u = q.top().pos;
        ll s = q.top().dist;
        q.pop();if (u == n) continue;
        bool ok = 0;
        if (q.empty()) ok = 1;
        for (int i = solver.head[u];i;i=solver.edges[i].next){
            int v = solver.edges[i].v;
            ll w = solver.edges[i].w;
            if (vis[v]) continue;
            if (s + w + solver.dist[v] == solver.dist[1]){
                q.push(Node(v,s+w));
                vis[v] = 1;
            }
        }

        if (ok){
            if (q.size() == 1){
                ans[{u,q.top().pos}] = 1;
                ans[{q.top().pos,u}] = 1;
            }
        }
    }

    for (int i = 1;i<m+1;i++){
        if (ans[{U[i],V[i]}]){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
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
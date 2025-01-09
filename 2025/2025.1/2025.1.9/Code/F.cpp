// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;

struct Node
{
    ll l,r;
    Node(int L,int R){
        l = L,r = R;
    }
    bool operator<(const Node& A) const{
        if(l!=A.l) return l < A.l;
        return r > A.r;
    }
};


void solve(){
    ll n,m,q;
    cin >> n >> m >> q;
    vector<Node> nodes;
    nodes.push_back(Node(m,m));
    while (q--){
        ll u;
        cin >> u;
        vector<Node> new_nodes;
        for (int i = 0;i<nodes.size();i++){
            if (u < nodes[i].l){
                new_nodes.push_back(Node(nodes[i].l-1,nodes[i].r));
            }else if (u > nodes[i].r){
                new_nodes.push_back(Node(nodes[i].l,nodes[i].r+1));
            }else{
                if(nodes[i].l!=nodes[i].r)new_nodes.push_back(Node(nodes[i].l,nodes[i].r));
                new_nodes.push_back(Node(1,1));
                new_nodes.push_back(Node(n,n));
            }
        }

        for (int i = 0;i<new_nodes.size();i++){
            if (new_nodes[i].l <= 0) new_nodes[i].l = 1;
            if (new_nodes[i].r > n) new_nodes[i].r = n;
        }

        sort(new_nodes.begin(),new_nodes.end());
        while (!nodes.empty()) nodes.pop_back();
        nodes.push_back(new_nodes[0]);
        for (int i = 1;i<new_nodes.size();i++){
            if (new_nodes[i-1].l == new_nodes[i].l){
                continue;
            }else if (nodes.size()>0&&nodes[nodes.size()-1].r >= new_nodes[i].l){
                nodes[nodes.size()-1].r = max(nodes[nodes.size()-1].r,new_nodes[i].r);
            }else{
                nodes.push_back(new_nodes[i]);
            }
        }
        ll ans = 0;
        for (int i = 0;i<nodes.size();i++){
            ans += nodes[i].r - nodes[i].l + 1;
            // cout << nodes[i].l << " " << nodes[i].r << endl;
        }
        cout << ans << " ";
    }
    cout << "\n";
    return;
}

signed main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _ = 1;cin >> _;
    while (_--){
        solve();
    }
    return 0;
}
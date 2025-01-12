// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;

struct Node
{
    ll x;
    bool a,b;
    Node(ll X = 0,bool A = 0,bool B = 0){
        x = X,a = A,b = B;
    }
    bool operator<(const Node& A)const {
        return x < A.x;
    }
};


void solve(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1),b(n+1);
    
    for (int i = 1;i<n+1;i++) cin >> a[i];
    for (int i = 1;i<n+1;i++) cin >> b[i];

    vector<Node> nodes;
    for (int i = 1;i<n+1;i++){
        nodes.push_back(Node(a[i],1,0));
    }
    for (int i = 1;i<n+1;i++){
        nodes.push_back(Node(b[i],0,1));
    }

    sort(nodes.begin(),nodes.end());

    ll ans = 0;
    ll sum_peo = n,sum_bad = 0;
    ll delta_peo = 0,delta_bad = 0;
    for (int i = 0;i<nodes.size();i++){
        if (i-1>=0&&nodes[i].x != nodes[i-1].x){
            sum_peo += delta_peo,sum_bad += delta_bad;
            delta_peo = 0,delta_bad = 0;
        }
        if (nodes[i].a == 1){
            if (sum_bad <= k){
                ans = max(ans,sum_peo * nodes[i].x);
            }
            delta_bad++;
        }else{
            if (sum_bad <= k){
                ans = max(ans,sum_peo * nodes[i].x);
            }
            delta_bad--;
            delta_peo--;
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
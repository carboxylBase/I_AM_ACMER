// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000;

int n;
ll resA[N],resB[N];

class SegTree{
public:
    struct Node{
        ll maxV;
    }nodes[N*4];
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    Node merge(Node L,Node R){
        Node M;
        M.maxV = max(L.maxV,R.maxV);
        return M;
    }
    void build(int rt,int l,int r){
        if (l == r){
            nodes[rt].maxV = resA[l] - resB[l];
            return;
        }
        int mid = l + r >> 1;
        build(ls,l,mid),build(rs,mid+1,r);
        nodes[rt] = merge(nodes[ls],nodes[rs]);
    }
    void pd(int rt){

    }
    void update(int rt,int l,int r,int ql,int qr){
        if (ql <= l && r <= qr){
            return;
        }
        int mid = l+r>>1;
        pd(rt);
        if (ql <= mid){
            update(ls,l,mid,ql,qr);
        }
        if (qr >= mid + 1){
            update(rs,mid+1,r,ql,qr);
        }
        nodes[rt] = merge(nodes[ls],nodes[rs]);
        return;
    }
    Node query(int rt,int l,int r,int ql,int qr){
        if (ql <= l && r <= qr){
            return nodes[rt];
        }
        int mid = l+r>>1;
        pd(rt);
        if (ql > mid){
            return query(rs,mid+1,r,ql,qr);
        }else if (qr < mid + 1){
            return query(ls,l,mid,ql,qr);
        }else{
            return merge(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
        }
    }
};


struct Node
{
    ll a,b;
    bool operator<(const Node& A) const{
        if (a < b){
            if (A.a < A.b){
                return a < A.a;
            }else if (A.a == A.b){
                return 1;
            }else{
                return 1;
            }
        }else if (a == b){
            if (A.a < A.b){
                return 0;
            }else if (A.a == A.b){
                return a < A.a;
            }else{
                return 1;
            }
        }else{
            if (A.a < A.b){
                return 0;
            }else if (A.a == A.b){
                return 0;
            }else{
                return b > A.b;
            }
        }
    }
}nodes[N];

void solve(){
    cin >> n;
    ll sumA = 0,sumB = 0;
    for (int i = 1;i<n+1;i++){
        cin >> nodes[i].a >> nodes[i].b;
        sumA += nodes[i].a,sumB += nodes[i].b;
    }

    sort(nodes+1,nodes+1+n);

    // for (int i = 1;i<n+1;i++){
    //     cout << i << " " << nodes[i].a << " " << nodes[i].b << endl;
    // }

    ll ans = 0;

    for (int i = 1;i<n+1;i++){
        resA[i] = resA[i-1] + nodes[i].a;
        resB[i] = resB[i-1] + nodes[i-1].b;
        ans = max(ans,resA[i] - resB[i]);
    }

    if (sumA <= sumB - nodes[n].b){
        cout << ans + sumA << endl;
        return;
    }else{
        SegTree solver;
        solver.build(1,1,n);

        bool ok = 0;
        ll res = 1e18;

        for (int i = 1;i<n;i++){
            if (sumA <= sumB - nodes[i].b){
                ok = 1;
                ll ans1;
                if (i-1>=1) ans1 = solver.query(1,1,n,1,i-1).maxV;
                else ans1 = -1e18;
                ll ans2 = 0;
                if (1) ans2 = solver.query(1,1,n,i+1,n).maxV;
                ans2 += nodes[i].b - nodes[i].a;
                res = min(res,max(ans1,ans2));
               // cout << i << " " << res << " " << ans1 << " " << ans2 <<  endl;
            }
        }

        if (ok){
            cout << max(res,0ll) + sumA << endl;
            return;
        }

        cout << -1 << endl;
    }

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
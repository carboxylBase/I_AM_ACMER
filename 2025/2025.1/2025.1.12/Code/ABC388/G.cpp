// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 300000;
const ll MAX = 1e15;
int n,q;
ll a[N],f[N];

class SegTree{
public:
    struct Node{
        ll v;
    }nodes[N*4];
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    Node merge(Node L,Node R){
        Node M;
        M.v = max(L.v,R.v);
        return M;
    }
    void build(int rt,int l,int r){
        if (l == r){
            nodes[rt].v = f[l] - l;
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

void solve(){
    cin >> n;
    for (int i= 1;i<n+1;i++){
        cin >> a[i];
    }
    cin >> q;

    int pos = 1;

    for (int i = 1;i<n+1;i++){
        while (pos < n){
            if (a[pos] / 2 >= a[i]){
                break;
            }else{
                pos++;
            }
        }
        if (a[pos] / 2 >= a[i]){
            f[i] = pos;
        }else{
            f[i] = MAX;
        }
    }

    SegTree solver;
    solver.build(1,1,n);

    while (q--){
        int l,r;
        cin >> l >> r;
        int L = 1,R = (r - l + 1) / 2,mid;
        int ans = 0;
        while (L<=R){
            mid = L+R>>1;
            ll max_v = solver.query(1,1,n,l,l+mid-1).v;
            if (max_v <= r - l + 1 - mid){
                ans = mid;
                L = mid + 1;
            }else{
                R = mid - 1;
            }
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
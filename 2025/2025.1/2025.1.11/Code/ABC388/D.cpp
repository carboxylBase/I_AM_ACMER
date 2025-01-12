// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 600000;
ll n,a[N];
class SegTree{
public:
    struct Node{
        int sum,laz,len;
    }nodes[N*4];
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    Node merge(Node L,Node R){
        Node M;
        M.sum = L.sum + R.sum;
        M.len = L.len + R.len;
        M.laz = 0;
        return M;
    }
    void build(int rt,int l,int r){
        if (l == r){
            nodes[rt].sum = a[l];
            nodes[rt].laz = 0;
            nodes[rt].len = 1;
            return;
        }
        int mid = l + r >> 1;
        build(ls,l,mid),build(rs,mid+1,r);
        nodes[rt] = merge(nodes[ls],nodes[rs]);
    }
    void pd(int rt){
        nodes[ls].laz += nodes[rt].laz;
        nodes[rs].laz += nodes[rt].laz;
        nodes[ls].sum += nodes[rt].laz * nodes[ls].len;
        nodes[rs].sum += nodes[rt].laz * nodes[rs].len;
        nodes[rt].laz = 0;
        return;
    }
    void update(int rt,int l,int r,int ql,int qr,int v){
        if (l > r){
            return;
        }
        if (ql <= l && r <= qr){
            nodes[rt].sum += nodes[rt].len * v;
            nodes[rt].laz += v;
            return;
        }
        int mid = l+r>>1;
        pd(rt);
        if (ql <= mid){
            update(ls,l,mid,ql,qr,v);
        }
        if (qr >= mid + 1){
            update(rs,mid+1,r,ql,qr,v);
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
    for (int i = 1;i<n+1;i++){
        cin >> a[i];
    }
    SegTree solver;
    solver.build(1,1,n);
    for (int i = 1;i<n+1;i++){
        ll sum = solver.query(1,1,n,i,i).sum;
        ll R;
        if (sum >= n - i){
            R = n;
            sum -= n - i;
        }else{
            R = i + sum;
            sum = 0;
        }
        cout << sum << " ";
        solver.update(1,1,n,i+1,R,1);
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
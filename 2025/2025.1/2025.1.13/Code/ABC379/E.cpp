// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000;

int n;string s;
class SegTree{
public:
    struct Node{
        ll sum,laz;
    }nodes[N*4];
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    Node merge(Node L,Node R){
        Node M;
        M.laz = 0;M.sum = L.sum + R.sum;
        return M;
    }
    void build(int rt,int l,int r){
        if (l == r){
            nodes[rt].laz = 0,nodes[rt].sum = 0;
            return;
        }
        int mid = l + r >> 1;
        build(ls,l,mid),build(rs,mid+1,r);
        nodes[rt] = merge(nodes[ls],nodes[rs]);
    }
    void pd(int rt){
        nodes[ls].laz += nodes[rt].laz;
        nodes[rs].laz += nodes[rt].laz;

        nodes[ls].sum += nodes[rt].laz;
        nodes[rs].sum += nodes[rt].laz;

        nodes[rt].laz = 0;
        return; 
    }
    void update(int rt,int l,int r,int ql,int qr,ll v){
        if (ql <= l && r <= qr){
            nodes[rt].sum += v;
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
    cin >> n >> s;
    SegTree solver;
    solver.build(1,1,n);

    for (int i = 1;i<n+1;i++){
        int num = s[i-1] - '0';
        ll t = i;
        solver.update(1,1,n,1,n - i + 1,t * num);
    }

    vector<ll> q;
    for (int i = 1;i<n+1;i++){
        q.push_back(solver.query(1,1,n,i,i).sum);
    }

    for (int i = 0;i<q.size()-1;i++){
        q[i+1] += q[i] / 10;
        q[i] %= 10;
    }

    while (q[q.size()-1] > 10){
        q.push_back(q[q.size()-1] / 10);
        q[q.size()-2] %= 10;
    }

    for (int i = q.size() - 1;i>=0;i--){
        cout << q[i];
    }
    cout << endl;
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
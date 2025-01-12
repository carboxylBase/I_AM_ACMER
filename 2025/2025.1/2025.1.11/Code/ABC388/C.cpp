// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;

ll cnt,n,a[N];
map<ll,ll> idx;

struct Bit
{
    ll v[N];
    int lowbit(int x){
        return x & -x;
    }
    void add(int x){
        while(x<=cnt){
            v[x]++;
            x += lowbit(x);
        }
    }
    int get_sum(int x){
        ll res = 0;
        while (x > 0){
            res += v[x];
            x -= lowbit(x);
        }
        return res;
    }
}bit;


void solve(){
    cin >> n;
    for (int i = 1;i<n+1;i++) cin >> a[i];
    vector<ll> b;
    for (int i = 1;i<n+1;i++){
        b.push_back(a[i]),b.push_back(a[i]/2);
    }
    sort(b.begin(),b.end());

    for (int i = 0;i<b.size();i++){
        if (i - 1 >= 0 && b[i-1] == b[i]){
            continue;
        }
        idx[b[i]] = ++cnt;
    }

    for (int i = 0;i<cnt+1;i++){
        bit.v[i] = 0;
    }

    ll ans = 0;

    for (int i = 1;i<n+1;i++){

        bit.add(idx[a[i]]);
 ans += bit.get_sum(idx[a[i]/2]);
        // if (a[i] == a[i-1]){
        //     ans 
        // }else{
           
        // }

        // cout << ans << endl;
    }

    cout << ans;

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
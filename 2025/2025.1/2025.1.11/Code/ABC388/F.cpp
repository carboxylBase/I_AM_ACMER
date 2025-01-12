// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
#define int ll
ll n,m,a,b;
struct Node{
    ll l,r;
}nodes[N];

bool check(ll l,ll r){
    if (l > r){
        return 0;
    }
    for (int i = a;i<=b;i++){
        if ((r - l) / i * (b - i) >= (r - l) % i){
            return 1;
        }
    }
    // if ((r-l)/a * (b - a) >= (r - l) % a){
    //     return 1;
    // }
    return 0;
}

void solve(){
    cin >> n >> m >> a >> b;
    for (int i = 1;i<m+1;i++){
        cin >> nodes[i].l >> nodes[i].r;
    }

    vector<ll> pos;
    pos.push_back(1);

    for (int i = 1;i<m+1;i++){
        if (pos.size() == 0){
            break;
        }
        vector<ll> pp;
        vector<ll> qq;
        for (int j = 0;j<pos.size();j++){
            if (pos[j] < nodes[i].l){
                pp.push_back(pos[j]);
            }else if (pos[j] > nodes[i].r){
                qq.push_back(pos[j]);
            }
        }
        pos = pp;
        vector<ll> new_pos;
        for (int j = nodes[i].r - b + 1;j<=nodes[i].l-1;j++){
            for (int k = 0;k<pos.size();k++){
                if (check(pos[k],j)){
                    new_pos.push_back(j);
                    break;
                }
            }
        }
        // for (int i = 0;i<new_pos.size();i++){
        //     cout << new_pos[i] << " ";
        // }
        // cout << endl;
        vector<ll> q;
        map<ll,bool> vis;
        for (int j = 0;j<new_pos.size();j++){
            for (int k = a;k<=b;k++){
                if (!vis[k + new_pos[j]] && k + new_pos[j] > nodes[i].r){
                    q.push_back(k+new_pos[j]);
                    vis[k+new_pos[j]] = 1;
                }
            }
        }

        for (int i = 0;i<qq.size();i++){
            if (!vis[qq[i]]){
                vis[qq[i]] = 1;
                q.push_back(qq[i]);
            }
        }

        pos = q;
        // for (int i = 0;i<pos.size();i++){
        //     cout << pos[i] << " ";
        // }
        // cout << endl;
        // cout << endl;
    }

    // for (int i = 0;i<pos.size();i++){
    //     cout << pos[i] << " ";
    // }
    // cout << endl;

    bool ok = 0;
    for (int i = 0;i<pos.size();i++){
        if (check(pos[i],n)){
            ok = 1;
            break;
        }
    }

    for (int i = 0;i<pos.size();i++){
        if (pos[i] == n){
            ok = 1;
        }
    }

    if (ok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
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
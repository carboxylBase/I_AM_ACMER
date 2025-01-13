// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define DEBUG 1
const ll N = 2000000;

ll n,a[N];
map<ll,ll> cnts;

ll f(ll x){
    ll res = 0;
    while (x){
        if (x & 1){
            res++;
        }
        x >>= 1;
    }
    return res;
}

ll g(ll x){
    // ll res = f(x);
    // for (ll y = x + 1;;y++){
    //     if (f(y) == res){
    //         return y;
    //     }
    // }
    vector<ll> q;
    while (x){
        q.push_back(x % 2);
        x >>= 1;
    }

    bool ok = 0;

    // for (int i = q.size()-1;i>=0 && !ok;i--){
    //     if (q[i] == 0){
    //         if (i-1 >= 0 && q[i-1] == 1){
    //             swap(q[i-1],q[i]);
    //             ok = 1;
    //         }
    //     }
    // }


    for (int i = 0;i<q.size()-1;i++){
        if (q[i] == 1 && q[i+1] == 0){
            ok = 1;
            swap(q[i],q[i+1]);
            ll sum1 = 0;
            for (int j = 0;j<i;j++){
                if (q[j] == 1){
                    sum1++;
                }
                q[j] = 0;
            }
            for (int j = 0;j<i && sum1;j++){
                sum1--;
                q[j] = 1;
            }
            break;
        }
    }

    if (ok){
        ll res = 0;
        for (int i = q.size() - 1;i>=0;i--){
            res <<= 1;
            res += q[i];
        }
        return res;
    }else{
        // cout << "ok" << endl;
        sort(q.begin(),q.end());
        // for (int i = 0;i<q.size();i++){
        //     cout << q[i] << " ";
        // }
        // cout << endl;
        q.pop_back();
        q.push_back(0);
        sort(q.begin(),q.end());

        reverse(q.begin(),q.end());
        q.push_back(1);

        // for (int i = 0;i<q.size();i++){
        //     cout << q[i] << " ";
        // }
        // cout << endl;
        // q.push_back(0);
        // swap(q[q.size()-1],q[q.size()-2]);
        ll res = 0;
        for (int i = q.size() - 1;i>=0;i--){
            res <<= 1;
            res += q[i];
        }
        return res;
    }
}

void solve(){
    cin >> n;
    for (int i = 1;i<n+1;i++) {
        cin >> a[i];
        cnts[a[i]]++;
    }

    // cout <<g(6) << endl;

    sort(a+1,a+1+n);
    ll ans = 0;
    map<ll,bool> vis;
    vector<ll> ANS;
    for (int i = 1;i<n+1;i++){
        if (vis[a[i]]){
            continue;
        }
        vector<ll> q;
        ll res = 1;
        q.push_back(a[i]);
        while (cnts[g(a[i])]){
            a[i] = g(a[i]);
            vis[a[i]] = 1;
            q.push_back(a[i]);
            res ++;
        }
        if (ans < res){
            ans= res,ANS = q;
        }
    }
    cout << ans << endl;
    for (int i = 0;i<ANS.size();i++){
        cout << ANS[i] << " ";
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
// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;

ll n,m,k;
ll a[N];

priority_queue<ll> even,odd;

void solve(){
    cin >> n >> m >> k;
    for (int i = 1;i<n+1;i++){
        cin >> a[i];
        if (a[i] % 2 == 0){
            even.push(a[i]);
        }else{
            odd.push(a[i]);
        }
    }

    // cout << even.top() << endl;

    while ((m || k) && (odd.size() || even.size())){
        if (even.size() && odd.size()){
            if (m && k){
                if (odd.top() / 2 <= even.top() / 2){
                    m--;
                    ll c = even.top();
                    even.pop();
                    c /= 2;
                    if (c % 2 == 1){
                        odd.push(c);
                    }else{
                        if (c != 0) even.push(c);
                    }
                }else{
                    k--;
                    ll c = odd.top() - 1;
                    odd.pop();
                    if (c != 0) even.push(c);
                }
            }else if (m){
                m--;
                ll c = even.top();
                even.pop();
                c /= 2;
                if (c % 2 == 1){
                    odd.push(c);
                }else{
                    if (c != 0) even.push(c);
                }
            }else{
                k--;
                ll c = odd.top() - 1;
                odd.pop();
                if (c != 0) even.push(c);
            }
        }else if (even.size()){
            if (m == 0){
                break;
            }else{
                m--;
                ll c = even.top();
                even.pop();
                c /= 2;
                if (c % 2 == 1){
                    odd.push(c);
                }else{
                    if (c != 0) even.push(c);
                }
            }
        }else{
            if (k == 0){
                break;
            }else{
                k--;
                ll c = odd.top() - 1;
                odd.pop();
                if (c != 0) even.push(c);
            }
        }
    }

    ll ans = 0;
    while (!odd.empty()){
        // cout << odd.top() << endl;
        ans += odd.top(),odd.pop();
    }
    while (!even.empty()){
        // cout << even.top() << endl;
        ans += even.top(),even.pop();
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
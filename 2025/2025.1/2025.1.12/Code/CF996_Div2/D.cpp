// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;

ll n;
double a[N];
double l,k;

void solve(){
    cin >> n >> k >> l;
    for (int i = 1;i<n+1;i++) cin >> a[i];

    double pos = 0;
    double t = 0;
    pos = k;
    t = a[1];
    if (pos >= l){
        cout << (ll)(2 * t) << endl;
        return;
    }
    for (int i = 2;i<n+1;i++){
        if (pos >= a[i]){
            a[i] = min(pos,a[i]+t);
        }else{
            if (a[i] - t <= pos){
                a[i] = pos;
            }else{
                a[i] -= t;
            }
        }

       // cout << i << " " << a[i] << endl;

        if (a[i] > pos){
            if ((a[i]-pos)/2 + pos >= l){
                t += l - pos;
                cout << (ll)(2 * t) << endl;
                return;
            }
            t += (a[i] - pos) / 2;
            pos = (a[i] + pos) / 2;
            // cout << i << " " << a[i] << endl;
            pos += k;
        }else{
            pos = max(pos,a[i] + k);
        }

        if (pos >= l){
            cout << (ll)(2 * t) << endl;
            return;
        }
    }

    if (pos >= l){
        cout << (ll)(t * 2) << endl;
        return;
    }

    t += (l - pos);
    cout << (ll)(t * 2) << endl;
    return;
}

signed main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _ = 1;cin >>_;
    while (_--){
        solve();
    }
    return 0;
}
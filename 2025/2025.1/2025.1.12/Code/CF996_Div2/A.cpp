// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;

ll a[N],b[N],n;

void solve(){
    cin >> n;

    ll jian = 0,min_given = 1e18;
    for (int i = 1;i<n+1;i++){
        cin >> a[i];
    }

    for (int i = 1;i<n+1;i++){
        cin >> b[i];
    }

    for (int i = 1;i<n+1;i++){
        a[i] -= jian;
        if (a[i] < 0){
            cout << "No\n";
            return;
        }
        if(a[i] >= b[i]){
            min_given = min(min_given,a[i] - b[i]);
        }else{
            ll delta = b[i] - a[i];

            min_given -= delta;
            if (min_given < 0){
                cout << "No\n";
                return;
            }
            min_given = 0;

            jian += delta;
        }
    }

    cout << "Yes\n";

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
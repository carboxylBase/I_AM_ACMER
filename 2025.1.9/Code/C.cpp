// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;

int n,m,k;
int papers[N],ans[N];

void solve(){
    cin >> n >> m >> k;
    for (int i = 0;i<n+1;i++){
        ans[i] = papers[i] = 0;
    }
    for (int i = 1;i<m+1;i++){
        cin >> papers[i];
    }
    for (int i = 1;i<k+1;i++){
        cin >> ans[i];
    }
    if (k == n){
        for (int i = 1;i<m+1;i++){
            cout << 1;
        }
        cout << "\n";
    }else if (k == n-1){
        sort(ans+1,ans+1+k);
        for (int i = 1;i<n+1;i++){
            if (ans[i] != ans[i-1] + 1){
                for (int j = 1;j<m+1;j++){
                    if (papers[j] == i){
                        cout << 1;
                    }else{
                        cout << 0;
                    }
                }
                break;
            }
        }
        cout << "\n";
    }else{
        for (int i = 1;i<m+1;i++){
            cout << 0;
        }
        cout << "\n";
    }
    return;
}

signed main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--){
        solve();
    }
    return 0;
}
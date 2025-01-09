// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
int n;
int h[N];
bool vis[4000][4000];
int ans = 1;
void solve(){
    cin >> n;
    for (int i = 1;i<n+1;i++) cin >> h[i];
    for (int i = 1;i<n;i++){
        int cnt = 0;
        int sum = 0;
        int pos = 1;
        while (cnt < n){
            for (int j = pos;j<n+1;j++){
                if (!vis[i][j]){
                    pos = j + 1;
                    vis[i][j] = 1;
                    cnt++;
                    sum = 1;
                    for (int k = j+i;k<=n;k+=i){
                        if (h[k] != h[j]){
                            break;
                        }
                        vis[i][k] = 1;
                        cnt++;
                        sum++;
                    }
                    ans = max(ans,sum);
                    break;
                }
            }
        }
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
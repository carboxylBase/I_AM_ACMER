// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 300000;
const ll M = 20;

ll dp[1<<M][M+1];
int opt[M+1][N];
int mat[M+1][M+1];
int delta[M+1];

void solve(){
    int n,q;
    cin >> n >> q;
    for (int i = 0;i<q;i++){
        char c;
        int s;
        cin >> s >> c;
        if (c == '+'){
            opt[s][i+1] = 1;
        }else{
            opt[s][i+1] = -1;
        }
    }

    for (int i = 1;i<n+1;i++){
        delta[i] = 1;
        for (int j = 1;j<q+1;j++){
            delta[i] += max(opt[i][j],0);
        }
    }

    // for (int i = 1;i<n+1;i++){
    //     cout << delta[i] << " ";
    // }
    // cout << endl;
    // cout << endl;

    for (int i = 1;i<n+1;i++){
        for (int j = 1;j<n+1;j++){
            int l[2] = {0,0},r[2] = {0,0};
            for (int k = 1;k<q+1;k++){
                if (opt[i][k] == 1){
                    r[0]++;
                }else if (opt[i][k] == -1){
                    l[0]++;
                    if (l[0]>r[0]){
                        l[0] = r[0];
                    }
                }
                if (opt[j][k] == 1){
                    r[1]++;
                }else if (opt[j][k] == -1){
                    l[1]++;
                    if (l[1]>r[1]){
                        l[1] = r[1];
                    }
                }
                mat[i][j] = max(mat[i][j],r[0]-l[1]);
            }
        }
    }

    // for (int i = 1;i<n+1;i++){
    //     for (int j = 1;j<n+1;j++){
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int i = 1;i<=(1<<n)-1;i++){
        for (int k = 1;k<=n;k++){
            dp[i][k] = 0x3f3f3f3f;
        }
    }

    for (int i = 0;i<=(1<<n)-1;i++){
        for (int j = 0;j<n;j++){
            if ((1<<j)&i){

            }else{
                if (i == 0){
                    dp[(1<<j)^i][j+1] = delta[j+1];
                }else{
                    for (int k = 1;k<=n;k++){
                        if (!(1<<(k-1)&i)){
                            continue;
                        }
                        dp[(1<<j)^i][j+1] = min(dp[(1<<j)^i][j+1],dp[i][k]+mat[k][j+1]+delta[j+1]-delta[k]+1);   
                        // if ((1<<j)^i == 5 && j == 0){
                        //     cout << dp[i][k] << " " << mat[k][j+1] << 
                        // }
                    }
                }
            }
        }
    }

    // for (int i = 0;i<=(1<<n)-1;i++){
    //     for (int k = 1;k<n+1;k++){
    //         cout << dp[i][k] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = 0x3f3f3f3f;
    for (int i = 1;i<n+1;i++){
        ans = min(dp[(1<<n)-1][i],ans);
    }
    cout << ans << "\n";
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
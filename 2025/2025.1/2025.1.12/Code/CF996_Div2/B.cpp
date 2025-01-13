// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;

int n,m;
ll mat[2000][2000];
ll sum_hang[2000],sum_lie[2000];

void solve(){
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 1;i<n+1;i++){
        for (int j = 1;j<m+1;j++){
            cin >> mat[i][j];
        }
    }

    for (int i = 1;i<n+1;i++){
        sum_hang[i] = 0;
    }
    for (int j = 1;j<m+1;j++){
        sum_lie[j] = 0;
    }

    for (int i = 1;i<n+1;i++){
        for (int j = 1;j<m+1;j++){
            sum_hang[i] += mat[i][j];
            sum_lie[j] += mat[i][j];
        }
    }
    int x ,y;
    x = y = 1;
    ll sum = 0;
    for (int i = 0;i<s.length();i++){
        if (s[i] == 'D'){
            mat[x][y] = sum - sum_hang[x];
            sum_hang[x] += mat[x][y];
            sum_lie[y] += mat[x][y];
            x++;
        }else{
            mat[x][y] = sum - sum_lie[y];
            sum_lie[y] += mat[x][y];
            sum_hang[x] += mat[x][y];
            y++;
        }
    }
    
    ll res = 0;
    for (int i = 1;i<m+1;i++){
        res += mat[n][i];
    }

    mat[n][m] += sum - res;

    // for (int i = 1;i<n+1;i++){
    //     ll res = 0;
    //     for (int j = 1;j<m+1;j++){
    //         res += mat[i][j];
    //     }

    //     cout << res << endl;
    // }

    for (int i = 1;i<n+1;i++){
        for (int j = 1;j<m+1;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
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
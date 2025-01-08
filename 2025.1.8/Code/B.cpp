// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
int h,w,x,y;
string mat[N];
string opt;
bool vis[2000][2000];
int sum;
void solve(){
    cin >> h >> w >> x >> y;
    for (int i = 1;i<h+1;i++) cin >> mat[i],mat[i] = "0"+mat[i];
    cin >> opt;
    for (int i = 0;i<opt.length();i++){
        if (opt[i] == 'U'){
            if (x-1<=0||mat[x-1][y]=='#'){
                
            }else{
                x--;
                if (mat[x][y] == '@'){
                    if (vis[x][y] == 0){
                        vis[x][y] = 1;
                        sum++;
                    }
                }
            }
        }else if (opt[i] == 'D'){
            if (x+1>h||mat[x+1][y]=='#'){
                
            }else{
                x++;
                if (mat[x][y] == '@'){
                    if (vis[x][y] == 0){
                        vis[x][y] = 1;
                        sum++;
                    }
                }
            }
        }else if (opt[i] == 'L'){
            if (y-1<=0||mat[x][y-1]=='#'){
                
            }else{
                y--;
                if (mat[x][y] == '@'){
                    if (vis[x][y] == 0){
                        vis[x][y] = 1;
                        sum++;
                    }
                }
            }
        }else if (opt[i] == 'R'){
            if (y+1>w||mat[x][y+1]=='#'){
                
            }else{
                y++;
                if (mat[x][y] == '@'){
                    if (vis[x][y] == 0){
                        vis[x][y] = 1;
                        sum++;
                    }
                }
            }
        }
    }
    cout << x << " " << y << " " << sum << endl;
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
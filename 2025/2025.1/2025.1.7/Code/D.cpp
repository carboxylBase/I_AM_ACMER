// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
void solve(){
    string x;
    cin >> x;
    if (x.length() % 2 == 1){
        int y = x.length() + 1;
        for (int i = 1;i<=y/2;i++){
            if (i&1){
                cout << "11";
            }else{
                cout << "00";
            }
        }
    }else{
        bool bad = 0,ok = 0;
        ll pos,pos_bad;
        for (int i = 0;i<x.length() && !bad && !ok;i+=2){
            if (x[i] == x[i+1]){
                if (i-1>=0&&x[i-1]==x[i]){
                    x[i] = x[i+1] = x[i] + 1;
                    if (x[i] > '9'){
                        bad = 1;
                        pos_bad = i;
                    }
                    ok = 1;
                    pos = i+2;
                }else{
                }
            }else{
                if (x[i] > x[i+1]){
                    x[i+1] = x[i];
                    if (i-1>=0&&x[i-1]==x[i]){
                        x[i] = x[i+1] = x[i] + 1;
                        if (x[i] > '9'){
                            bad = 1;
                            pos_bad = i;
                        }
                    }else{
                    }
                }else{
                    x[i] = x[i+1] = x[i] + 1;
                    if (i-1>=0&&x[i-1]==x[i]){
                        x[i] = x[i+1] = x[i]+1;
                        if (x[i]>'9'){
                            bad = 1;
                            pos_bad = i;
                        }
                    }else{
                    }
                }
                ok = 1;
                pos = i+2;
            }
        }
        if (bad){
            bool yes = 0;
            for (int i = pos_bad-2;i>=0;i-=2){
                if (x[i] < '9'){
                    int delta = 0;
                    while (++delta + x[i] <= '9'){
                        if (i-1<0){
                            yes = 1;
                            break;
                        }
                        if (x[i] + delta != x[i-1]){
                            yes = 1;
                            break;
                        }
                    }
                    // cout << delta << endl;
                    if (!yes) continue;;
                    x[i] += delta;
                    x[i+1] = x[i];
                    for (int j = i+2;j<x.length();j+=2){
                        x[j] = x[j+1] = '0';
                        if (x[j-1] == x[j]){
                            x[j] = x[j+1] = '1';
                        }
                    }
                    cout << x;
                    return;
                }
            }
            int y = x.length() + 2;
            for (int i = 0;i<y/2;i++){
                if (i&1){
                    cout << "00";
                }else{
                    cout << "11";
                }
            }
        }else if (ok){
            for (int i = pos;i<x.length();i+=2){
                x[i] = x[i+1] = '0';
                if (x[i] == x[i-1]){
                    x[i] = x[i+1] = '1';
                }
            }
            cout << x;
        }else{
            cout << x;
        }
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
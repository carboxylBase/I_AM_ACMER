// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
void solve(){
    int len;
    string s;
    cin >> len >> s;
    vector<int> pos_p,pos_s;
    for (int i = 0;i<len;i++){
        if (s[i] == 'p'){
            pos_p.push_back(i);
        }else if (s[i] == 's'){
            pos_s.push_back(i);
        }
    }

    if (pos_p.size() && pos_s.size() && pos_p[0] < pos_s[pos_s.size()-1]){
        cout << "No\n";
        return;
    }

    for (int i = 0;i<pos_s.size();i++){
        if (pos_s[i] == 0){
            continue;
        }
        for (int j = 0;j<pos_p.size();j++){
            if (pos_p[j] == len - 1){
                continue;
            }
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n"; 
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
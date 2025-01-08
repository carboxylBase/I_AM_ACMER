// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
void solve(){
    string s;
    cin >> s;
    map<char,ll> vis1,vis2;
    ll max1 = 0,max2 = 0;
    for (int i = 0;i<s.length()/2;i++){
        vis1[s[i]]++;
        if (vis1[s[i]] > max1){
            max1 = vis1[s[i]];
        }
    } 
    for (int i = s.length()/2;i<s.length();i++){
        vis2[s[i]]++;
        if (vis2[s[i]] > max2){
            max2 = vis2[s[i]];
        }
    }
    cout << s.length() - max1 - max2;
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
// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
const ll N = 2000000;
void solve(){
    ll n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    char a;
    map<char,ll> mat;
    for (int i = 0;i<n;i++){
        mat[s[i]]++;
        //ans = max(ans,mat[s[i]]);
        if (ans < mat[s[i]]){
            ans = mat[s[i]],a = s[i];
        }
    }
    cout << a;
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
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    //freopen("input.txt","r",stdin);
	int n,m;
	ll x,y;
	cin >> n >> m >> x >> y;
	
	map<ll,set<ll>>xy;//xy[i]={j s.t. (i,j) に家}
	map<ll,set<ll>>yx;//yx[j]={i s.t. (i,j) に家}
	
	for(int i=0;i<n;i++){
		int xx,yy;
		cin >> xx >> yy;
		xy[xx].insert(yy);
		yx[yy].insert(xx);
	}
	
	int ans=0;
	for(int i=0;i<m;i++){
		char c;
		int d;
		cin >> c >> d;
		if(c=='U'){
			ll new_y=y+d;
			auto it=xy[x].lower_bound(y);
			while(it!=xy[x].end()&&*it<=new_y){
				ans++;
				yx[*it].erase(x);
				it=xy[x].erase(it);
			}
			y=new_y;
		}else if(c=='D'){
			ll new_y=y-d;
			auto it=xy[x].lower_bound(new_y);
			while(it!=xy[x].end()&&*it<=y){
				ans++;
				yx[*it].erase(x);
				it=xy[x].erase(it);
			}
			y=new_y;
		}else if(c=='L'){
			ll new_x=x-d;
			auto it=yx[y].lower_bound(new_x);
			while(it!=yx[y].end()&&*it<=x){
				ans++;
				xy[*it].erase(y);
				it=yx[y].erase(it);
			}
			x=new_x;
		}else if(c=='R'){
			ll new_x=x+d;
			auto it=yx[y].lower_bound(x);
			while(it!=yx[y].end()&&*it<=new_x){
				ans++;
				xy[*it].erase(y);
				it=yx[y].erase(it);
			}
			x=new_x;
		}
	}
	
	cout << x << ' ' << y << ' ' << ans << endl;
}

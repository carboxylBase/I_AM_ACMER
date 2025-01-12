// It's a wonderful life.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG 1
#define int ll
const ll N = 200000;

int n,q,a[N],id[N],x[N];

struct Block
{
    int fa,MAX,needs,sum;
    int L,R;
    int others;
    map<int,int> q;
    void del(int num){
        q[num]--;
        if (MAX >= num){
            sum--;
            if (q[num] == 0){
                needs++;
            }
        }else{
            others--;
        }
        if (q[num] == 0){
            q.erase(num);
        }
        return;
    }
    void add(int num,int times){
        // if (times == 0){
        //     return;
        // }
        if (q[num] == 0 && num <= MAX){
            needs--;
        }
        q[num]+=times;
        if (num > MAX){
            others+=times;
        }else{
            sum+=times;
        }
        return;
    }
    int size(){
        return q.size();
    }
    int get_ans(){
        if (needs != 0 || others){
            return 0;
        }
        return sum;
    }
};


struct Node
{
    multiset<int> ans;
    int MAX;
    Block blocks[N];
    Node(int M = 0){
        MAX = M;
    }
    void init(){
        auto it = ans.begin();
        while (it != ans.end()){
            it = ans.erase(it);
        }
        for (int i = 1;i<n+1;i++){
            auto it = blocks[i].q.begin();
            while (it != blocks[i].q.end()){
                it = blocks[i].q.erase(it);
            }
            blocks[i].MAX = MAX;
            blocks[i].fa = i;
            blocks[i].needs = MAX + 1;
            blocks[i].others = 0;
            blocks[i].sum = 0;
            blocks[i].L = i-1,blocks[i].R = i+1;
        }
        return;
    }
    int f(int u){
        if (blocks[u].fa == u){
            return u;
        }
        return blocks[u].fa = f(blocks[u].fa);
    }
    int merge(int u,int v){
        int fu = f(u),fv = f(v);
        // cout << blocks[fu].size() << " " << blocks[fv].size() << endl;
        // cout << fu << " " << fv << endl;
        if (blocks[fu].size() > blocks[fv].size()){
            swap(fu,fv);
        }
        // cout << fu << " " << fv << endl;
        // cout << blocks[fu].size() << " " << blocks[fv].size() << endl;
        ans.erase(ans.find(blocks[fv].get_ans()));
        ans.erase(ans.find(blocks[fu].get_ans()));
        auto it = blocks[fu].q.begin();
        while (it != blocks[fu].q.end()){
            // blocks[fv].q.insert(*it);
            // cout << "ok" << endl;
            // if(it->second > 0) 
            // while (it->second--){
            //     blocks[fv].add(it->first);
            // }
            blocks[fv].add(it->first,it->second);
            it = blocks[fu].q.erase(it);
        }
        ans.insert(blocks[fv].get_ans());
        // cout << blocks[fv].size() << endl;
        // cout << blocks[fv].sum << " " << blocks[fv].sum << " "  << fv << endl;
        blocks[fu].fa = fv;
        if (blocks[fv].L == fu){
            blocks[fv].L = blocks[fu].L;
            blocks[blocks[fu].L].R = fv;
        }else{
            blocks[fv].R = blocks[fu].R;
            blocks[blocks[fu].R].L = fv;
        }
        // ans.insert(blocks[fv].get_ans());
        // cout << fv << "sss" << blocks[fv].size() << endl;
        // cout << 1 << " " << blocks[1].size() << endl;
        return fv;
    }
    void update(int idx,bool ok){
        int aimer = f(id[idx]);
        // cout << "ss" << aimer << endl;
        // cout << blocks[aimer].size() << endl;
        ans.erase(ans.find(blocks[aimer].get_ans()));
        blocks[aimer].del(a[id[idx]]);
        // cout << blocks[aimer].size() << endl;
        blocks[aimer].add(a[id[idx]] - x[idx],1);
        // cout << blocks[aimer].size() << endl;
        // cout << a[id[idx]] << "sss" << x[idx] << endl;
        // cout << a[id[idx]] << " " << a[id[idx]] - x[idx] << " " << id[idx] << " " << idx << endl;
        ans.insert(blocks[aimer].get_ans());
        // cout << aimer << endl;
        if (blocks[aimer].others != 0){
            // if (ok){
            //     cout << aimer << " " << blocks[aimer].others << endl;
            // }
            // cout << "ok" << endl;
            return;
        }
        // if (blocks[aimer].L > 0){
        //     blocks[aimer].L = blocks[f(blocks[aimer].L)].L;
        // }
        // if (blocks[aimer].R <= n){
        //     blocks[aimer].R = blocks[f(blocks[aimer].R)].R;
        // }
        if (blocks[aimer].L > 0 && blocks[blocks[aimer].L].others == 0){
            // cout << "ok" << endl;
            if (blocks[aimer].L != aimer){
                // ans.erase(blocks[aimer].get_ans());
                aimer = merge(blocks[aimer].L,aimer);
                // ans.insert(blocks[aimer].get_ans());
                // blocks[aimer].L = blocks[blocks[aimer].L].L;
            }
        }

        // aimer = f(aimer);

        if (blocks[aimer].R <= n && blocks[blocks[aimer].R].others == 0){
            // cout << "ok" << endl;
            if (blocks[aimer].R != aimer){
                // ans.erase(blocks[aimer].get_ans());
                aimer = merge(blocks[aimer].R,aimer);
                // ans.insert(blocks[aimer].get_ans());
                // blocks[aimer].R = blocks[blocks[aimer].R].R;
            }
        }

        // ans.insert(blocks[aimer].get_ans());

        return;
    }
    int get_ans(){
        // ll res = 0;
        // for (int i = 1;i<n+1;i++){
        //     res = max(blocks[f(i)].get_ans(),res);
        // }
        // return res;
        return *ans.rbegin();
    }
};

vector<Node> nodes;

void solve(){
    cin >> n >> q;
    for (int i = 1;i<n+1;i++) {
        cin >> a[i];
    }

    for (int i = 1;i<q+1;i++){
        cin >> id[i] >> x[i];
        a[id[i]] += x[i];
    }

    for (int i = 0;i<nodes.size();i++){
        nodes[i].init();
    }

    for (int i = 1;i<n+1;i++){
        id[i+q] = i,x[i+q] = 0;
    }

    for (int i = 0;i<nodes.size();i++){
        for (int j = 1;j<n+1;j++){
            // cout << j << endl;
            nodes[i].blocks[j].add(a[j],1);
            nodes[i].ans.insert(nodes[i].blocks[j].get_ans());
        }
    }

    // for (int i = 0;i<nodes.size();i++){
    //     for (int j = 1;j<=n;j++){
    //         cout << nodes[i].blocks[j].others << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 1;i<n+1;i++){
    //     cout << nodes[0].blocks[i].others << " ";
    // }
    // cout << endl;

    for (int i = 0;i<nodes.size();i++){
        for (int j = 1+q;j<n+q+1;j++){
            // cout << j << endl;
            nodes[i].update(j,0);
            // cout << "sss" << nodes[1].blocks[2].L << " " << nodes[1].blocks[2].R << endl;
            // cout << nodes[1].blocks[1].size() << endl;
            // cout << nodes[i].blocks[1].size() << endl;
            // cout << id[j] << endl;
            // if (j == 3+q){
            //     cout << nodes[i].blocks[3].others << endl;
            // }
            // cout << nodes[0].blocks[3].others << endl;
            // for (int k = 1;k<n+1;k++){
            //     cout << nodes[i].blocks[k].fa << " ";
            // }
            // cout << endl;
        }
    }

    // cout << endl;
    // cout << endl;
    // cout << nodes[1].blocks[1].size() << endl;

    // for (int i = 0;i<nodes.size();i++){
    //     for (int j = 1;j<n+1;j++){
    //         cout << nodes[i].f(j) << " ";
    //     }
    //     cout << endl;
    // }

    // cout << nodes[1].blocks[1].size() << endl;
    vector<int> ANS;

    for (int i= q;i>0;i--){
        int ans = 0;
        for (int j = 0;j<nodes.size();j++){
            ans = max(ans,nodes[j].get_ans());
        }
        ANS.push_back(ans);
        for (int j = 0;j<nodes.size();j++){
            bool yes = 0;
            if (i == q && j == 1){
                yes = 1;
            }
            nodes[j].update(i,yes);
           // ans = max(ans,nodes[j].get_ans());
        }
        // if (i == q){
        //     cout << nodes[1].blocks[4].sum << endl;
        // }
        // cout << nodes[1].blocks[1].size() << endl;
        a[id[i]] -= x[i];
        // for (int i = 1;i<n+1;i++){
        //     cout << nodes[2].f(i) << " ";
        // }
        // cout << endl;
        // for (int i = 1;i<n+1;i++){
        //     cout << nodes[2].blocks[i].get_ans() << " ";
        // }
        // cout << endl;
        // for (int i = 1;i<n+1;i++){
        //     cout << a[i] << "s";
        // }
        // cout << endl;
        // for (auto it : nodes[2].ans){
        //     cout << it << " ";
        // }
        // cout << endl;
        // for (int i = 1;i<n+1;i++){
        //     cout << nodes[2].blocks[nodes[1].f(i)].sum << "z";
        // }
        // cout << endl;
    }

    for (int i = q-1;i>-1;i--){
        cout << ANS[i] << "\n";
    }
    return;
}

signed main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    nodes.push_back(Node(0));
    while (1){
        int new_b = nodes[nodes.size()-1].MAX + 1;
        new_b *= 2,new_b--;
        if (new_b > 1e5) break;
        nodes.push_back(Node(new_b));
    }
    int _ = 1;cin >> _;

    while (_--){
        solve();
    }
    return 0;
}
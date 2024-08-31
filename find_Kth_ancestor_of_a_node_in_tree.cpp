#include<bits/stdc++.h>
using namespace std;

#define              MOD  1000000007
#define             MOD1  998244353
#define               ll  long long
#define                N  200005


ll n, m, x, y, w, a, b, c, d, k, l, r, q;
string s, sa, sb, str;

vector<ll> adj[101];
ll ancestors[101][6];

void dfs(ll node, ll par){
    ancestors[node][0] = par;
    for(auto it:adj[node]){
        if(it != par){
            dfs(it, node);
        }
    }
}

void preprocessing(){
    //calculate upto logn
    for(int i = 1; i <= log2(n) + 1; i++){
        for(int j = 1; j <= n; j++){
            ancestors[j][i] = ancestors[ancestors[j][i-1]][i-1];
        }
    }
}

ll findKthAncestor(ll node, ll k){
    for(int i = 31; i >= 0; i--){
        if((1<<i) & k){
            node = ancestors[node][i];
        }
    }
    return node;
}


void solve(){
    bool ok = true, can = false;
    ll tot = 0, mn = LLONG_MAX, mx = LLONG_MIN, sum = 0;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1ll, 0ll);
    preprocessing();
    cout << findKthAncestor(9, 3) << endl;

}

int main(){
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}


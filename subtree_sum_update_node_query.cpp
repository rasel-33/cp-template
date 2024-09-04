#include<bits/stdc++.h>
using namespace std;

#define              MOD  1000000007
#define             MOD1  998244353
#define               ll  long long
#define                N  200005
#define              EPS  1e-12

ll n, m, x, y, w, a, b, c, d, k, l, r, q;
string s, sa, sb, str;
vector<ll> traversal;
vector<ll> adj[N];
vector<ll> sz(N);
vector<ll> linking(N);

ll dfs(ll node, ll par){
    traversal.push_back(node);
    sz[node] = 1;
    for(ll child:adj[node]){
        if(child != par){
            sz[node] += dfs(child, node);
        }
    }
    return sz[node];
}

struct BIT {
    vector<ll> bit;
    BIT(vector<ll> a) {
        bit = vector<ll>(a.size() + 1, 0);
        for (int i = 0; i < a.size(); i++) {
            add(i + 1, a[i]);
        }
    }
    void add(int i, ll x) {
        for (; i < bit.size(); i += i & -i) {
            bit[i] += x;
        }
    }
    ll sum(int i) {
        ll res = 0;
        for (; i > 0; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }
    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void increase(int i, ll x) {
        for (; i < bit.size(); i += i & -i) {
            bit[i] += x;
        }
    }
    void update(int i, ll x) {
        add(i, x - sum(i, i));
    }
};

void update_node_value(BIT &bit, ll node, ll val){
    ll pos = linking[node];
    bit.update(pos+1, val);
}

ll get_subtree_sum(BIT &bit, ll node){
    ll pos = linking[node];
    return bit.sum(pos+1, pos + sz[traversal[pos]]);
}
// linking is used to find index of a node in the traversal vector


void solve(){
    bool ok = true, can = false;
    ll tot = 0, mn = LLONG_MAX, mx = LLONG_MIN, sum = 0;
    cin >> n;
    vector<ll> val(n+1);
    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }
    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1);

    vector<ll> ar(n);
    for(int i = 0; i < n; i++){
        linking[traversal[i]] = i;
    }
    for(int i = 0; i < n; i++){
        ar[i] = val[traversal[i]];
    }

    BIT bit(ar);

    update_node_value(bit, 6, 100);
    cout << get_subtree_sum(bit, 2) << endl;

}

int main(){
    int tc = 1;
    // cin >> tc;

    while(tc--){
        solve();
    }
}


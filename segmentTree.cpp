#include<bits/stdc++.h>
using namespace std;


struct segTree{
    int sz;
    vector<ll> sgtree;
    void init(int n){
        sz = 1;
        while(sz < n) sz *= 2;
        sgtree.assign(2*sz, 0ll);
    }

    void set(ll node, ll b, ll e, ll i, ll val){
        if(i>e || i<b) return;
        if(b >= i && e <= i){
            sgtree[node] = val; return;
        }
        ll left = node*2;
        ll right = node*2+1;
        ll mid = (b + e)/2;
        set(left, b, mid, i, val);
        set(right, mid+1, e, i, val);
        sgtree[node] = sgtree[left] + sgtree[right];
    }

    // node = nodeNo. in the tree, b = begin of range of that node, e = end of the range of that node, 
    // i = start of the query range, j = end of the query range
    // here i, j both are inclusive
    ll query(ll node, ll b, ll e, ll i, ll j){
        if(i > e || j < b)return 0;
        if(b >= i && e <= j)return sgtree[node];
        ll left = node*2;
        ll right = node*2+1;
        ll mid = (b+e)/2;
        ll p1 = query(left, b, mid, i, j);
        ll p2 = query(right, mid+1, e, i, j);
        return p1+p2;
    }

    void setValue(ll i, ll val){
        set(1, 1, sz, i, val);
    }

    ll getQuery(ll l, ll r){
        return query(1, 1, sz, l, r);
    }

    void PrintTree(){
        for(int i=1;i<=2*sz;i++){
            cout << sgtree[i] <<" ";
        }
        cout << endl;
    }
};

void solve(int tc){
    bool ok = true, can = false;
    ll  sum = 0, mx = -1e18, mn = 1e18, tot=0;
    
}

int main(){
    int tc = 1, cas_no = 0;
    cout << fixed << setprecision(10);
    // scanf("%d", &tc);
    // cin >> tc;
    while(tc--){++cas_no;solve(cas_no);}return 0;
}

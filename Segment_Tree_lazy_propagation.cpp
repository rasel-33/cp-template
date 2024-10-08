#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(...);
#define debug(...);
#define crndl ;
#endif


#define              ll   long long
#define             MOD   1000000007
#define               N   100005

ll n, x, y, z, k, q, m, a, b, c, r, l;
string s, sa, sb;




ll arr[N];


struct ST{
    #define lc (n<<1)
    #define rc ((n<<1)|1)
    ll t[4*N], lazy[4*N];

    ST(){
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }

    void push(int n, int lo, int hi){
        if(lazy[n] == 0) return;
        t[n] = t[n] + lazy[n] * 1ll *(hi - lo + 1);
        if(lo != hi){
            lazy[lc] += lazy[n];
            lazy[rc] += lazy[n];
        }   
        lazy[n] = 0;
    }

    void pull(int n){
        t[n] = t[lc] + t[rc];
    }

    ll combine(ll a, ll b){
        return a+b;
    }

    void build(int n, int lo, int hi){
        lazy[n] = 0;
        if(lo == hi){
            t[n] = arr[lo];
            return;
        }
        int mid = (lo + hi) >> 1;
        build(lc, lo, mid);
        build(rc, mid+1, hi);
        pull(n);
    }

    void update(int n, int lo, int hi, int i, int j, int val){
        push(n, lo, hi);
        if(j < lo || hi < i) return;
        if(i <= lo && hi<=j){
            lazy[n] = val; //set lazy
            push(n, lo, hi);
            return;
        }
        int mid = (lo + hi) >> 1;
        update(lc, lo, mid, i, j, val);
        update(rc, mid+1, hi, i, j, val);
        pull(n);
    }

    ll query(int n, int lo, int hi, int i, int j){
        push(n, lo, hi);
        if(lo > j || hi < i) return 0;
        if(lo>=i && hi <= j) return t[n];
        int mid = (lo + hi) >> 1;
        return combine(query(lc, lo, mid, i, j) ,  query(rc, mid+1, hi, i, j));
    }
};



void solve(){
    bool ok = true, can = false;
    ll tot = 0, mn = LLONG_MAX, mx = LLONG_MIN, sum = 0;

    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        arr[i] = 0;
    }
    ST st;
    st.build(1, 1, n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            cin >> l >> r;
            l++;
            r++;
            cout << st.query(1, 1, n, l, r) << endl;
        }
        else{
            int val;
            cin >> l >> r >> val;
            l++;
            r++;
            st.update(1, 1, n, l, r, val);
        }
    }
    

}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // freopen("output.txt", "w", stdout);
    // cout << setprecision(4);

    int test = 1;
    cin >> test;

    for(int i = 1; i <= test; i++){
        cout << "Case "<<i<<":"<<endl;
        solve();
    }
    return 0;
}

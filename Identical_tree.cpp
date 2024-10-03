#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(...);
#define debug(...);
#define crndl;
#endif

#define              MOD  1000000007
// #define             MOD1  998244353
// #define             MOD2  972663749
#define              EPS  1e-12
#define               PI  2*acos(0.0)
#define               ll  long long
#define              pii  pair<int, int>     
#define              pll  pair<ll,ll>
#define               pb  push_back
#define        UNIQUE(v)  (v).erase(unique(all(v)), (v).end())
#define               ff  first
#define               ss  second
#define         coutv(v)  for(auto it:v)cout<<it<<' ';cout<<endl;
#define          cinv(v)  for(auto &it:v)cin>>it;
#define         lcm(a,b)  (a*b)/__gcd(a,b)
#define           srt(v)  sort((v).begin(),(v).end());
#define          rsrt(v)  sort((v).rbegin(),(v).rend());
#define            sz(x)  ((int)(x).size())
#define           all(x)  (x).begin(), (x).end()
#define          rall(x)  (x).rbegin(),(x).rend()
#define      countbit(x)  __builtin_popcount(x)
#define     SetBit(x, k)  (x |= (1LL << k))
#define   ClearBit(x, k)  (x &= ~(1LL << k))
#define   CheckBit(x, k)  ((x>>k)&1)
#define Toggle_Bit(x, k)  (x ^= (1 << k))
bool casprint= false;
bool multiple= false;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
//moves
int kdx[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };//knights move
int kdy[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };//knights move
int dx[] = { -1,+0,+1,+0,-1,-1,+1,+1};
int dy[] = { +0,-1,+0,+1,+1,-1,+1,-1};
////////////  U  L  D  R

template <typename T> T     MIN (T a,T b){return min(a, b);}
template <typename T> T     MAX (T a,T b){return max(a, b);}

// random function
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll my_rand(ll l, ll r)
{
    return uniform_int_distribution<ll>(l, r) (rng);
}

// predefined functions
ll power(ll a, ll b){if(b==0) return 1;if(b&1) return a*power(a, b-1);ll ret = power(a, b/2);return ret*ret;}
ll expo(ll a, ll b, ll m){if(b == 0) return 1ll;ll ret = expo(a, b/2, m);ret = (ret%m * ret%m)%m;if(b%2) ret = (ret*a)%m;return ret;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
void printArray(ll *ar, ll sz){if(sz == 0){cout << endl;return;}for(int i=0;i<sz-1;i++){cout << ar[i] <<" ";}cout << ar[sz-1] << endl;}
void printVector(vector<ll>&vt){int sz = vt.size();if(sz==0){cout << endl;return;}for(int i=0;i<sz-1;i++){cout << vt[i] <<" ";}cout << vt[sz-1] << endl;}




ll n, m, x, y, a, b, c, k;
string s, sa, sb, str;

const int N = 2e5 + 5;
const int base = 27;

ll rn1, rn2;
vector<int> tree1[N];
vector<int> tree2[N];
vector<ll> po(N);

void pre(){
    ll cur = base;
    for(int i = 1; i < N; i++){
        po[i] = cur;
        cur *= base;
        cur %= MOD;
    }
}

ll dfs(int tr, int node, int par, int lvl){
    ll hs = (rn1 * po[lvl]) % MOD;
    if(tr==1){
        for(int it:tree1[node]){
            if(it == par) continue;
            hs += dfs(tr, it, node, lvl+1);
            hs %= MOD;
        }
    }
    else{
        for(int it:tree2[node]){
            if(it == par) continue;
            hs += dfs(tr, it, node, lvl+1);
            hs %= MOD;
        }
    }
        
    hs = (hs + ((rn2 * po[lvl]) % MOD)) % MOD;
    return hs;
}




void solve(){
    bool ok = true, can = false;
    ll  sum = 0, mx = LLONG_MIN, mn = LLONG_MAX, tot=0, q;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        tree1[x].push_back(y);
        tree1[y].push_back(x);
    }

    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        tree2[x].push_back(y);
        tree2[y].push_back(x);
    }

    if(dfs(1, 1, -1, 1) == dfs(2, 1, -1, 1)){
        cout << "Identical" << endl;
    }
    else{
        cout << "Not identical" << endl;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << fixed << setprecision(10);
    // multiple = 1;
    // casprint = 1;
    rn1 = my_rand(1, 26);
    rn2 = my_rand(1, 26);
    pre();
    int tc = 1, cas_no = 0;time_t start = clock();
    if(multiple){cin >> tc;}
    while(tc--){++cas_no;if(casprint){cout <<"Case "<<cas_no<<": ";}solve();}
    
#ifdef _DEBUG
    cerr << "Completed Successfully in " << (1000.0 * (double)(clock() - start) / CLOCKS_PER_SEC) << "ms---->  \n";
#endif
return 0;
}

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
#define             MOD1  998244353
#define             MOD2  972663749
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

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

//moves
int kdx[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };//knights move
int kdy[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };//knights move
int dx[] = { -1,+0,+1,+0,-1,-1,+1,+1};
int dy[] = { +0,-1,+0,+1,+1,-1,+1,-1};

template <typename T> T     MIN (T a,T b){return min(a, b);}
template <typename T> T     MAX (T a,T b){return max(a, b);}



// predefined functions
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

    

void solve(){
    bool ok = true, can = false;
    ll  sum = 0, mx = LLONG_MIN, mn = LLONG_MAX, tot=0, q;
    
}

int main(){
    ios::sync_with_stdio(0);
    // cout << fixed << setprecision(10);
    int tc = 1, cas_no = 0;time_t start = clock();
    // scanf("%d", &tc);

    // cin >> tc;

    while(tc--){++cas_no;
    // printf("Case %d: ",cas_no);

    solve();}
    
#ifdef _DEBUG
    printf("------- OUTPUT ENDS --------------\n");
    printf("-------Elapsed time: %lld ms--------- ", (ll)(1000.0 * (double)(clock() - start) / CLOCKS_PER_SEC));
#endif
return 0;
}

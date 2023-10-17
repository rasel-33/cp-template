#include<bits/stdc++.h>
using namespace std;

#ifdef RASEL
#include "debug.h"
#else
#define dbg(...);
#define debug(...);
#define crndl;
#endif


#define MOD          1000000007
#define MOD1         998244353
#define MOD2         972663749
#define EPS          1e-12
#define ll           long long
#define pll          pair<ll,ll>
#define pb           push_back
#define UNIQUE(v)    (v).erase(unique(all(v)), (v).end())
#define ff           first
#define ss           second
#define sz(x)        ((int)(x).size())
#define all(x)       (x).begin(), (x).end()
#define countbit(x)  __builtin_popcount(x)

//moves
int kdx[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };//knights move
int kdy[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };//knights move
int dx[] = { -1,+0,+1,+0,-1,-1,+1,+1};
int dy[] = { +0,-1,+0,+1,+1,-1,+1,-1};

template <typename T> void  yes(T a){if(a==1)printf("Yes\n");else printf("YES\n");}
template <typename T> void  no(T a){if(a==1)printf("No\n");else printf("NO\n");}
template <typename T> T     min (T a,T b){return min(a, b);}
template <typename T> T     max (T a,T b){return max(a, b);}

ll expo(ll a, ll b, ll m){if(b == 0) return 1ll;ll ret = expo(a, b/2, m);ret = (ret%m * ret%m)%m;if(b%2) ret = (ret*a)%m;return ret;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;} 

ll n, m, k, x, y, h, a, b, c, d, e, f,q, r, w, p, g, X1, X2, Y1, Y2, xdiff, ydiff,z, i, j;
string s, sa, sb, str;


ll ar[200005], br[100005], cr[100005];
ll gg[1001][1001];



void solve(){
    bool ok = true, can = false;
    ll  sum = 0, mx = 0, mn = 1e18, tot=0, len, idx;


}



int main(){
#ifdef RASEL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w",stdout);
    printf("------------------------------------\n"); time_t start = clock();
#endif
    // cout << fixed << setprecision(10);

    int tc = 1, cas_no = 0;
    // scanf("%d", &tc);
    while(tc--){++cas_no;
    // printf("Case %d: ",cas_no);
    solve();
    }

#ifdef RASEL
    printf("\n--------Executed Succesfully--------\n");
    fprintf(stderr, "Elapsed time: %lld ms    ", (ll)(1000.0 * (double)(clock() - start) / CLOCKS_PER_SEC));
    printf("\nCheck constraints and delcared size\n");
#endif
return 0;
}

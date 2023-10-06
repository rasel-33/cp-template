#include<bits/stdc++.h>
using namespace std;
#define MOD    1000000007
#define ll     long long

ll expo(ll a, ll b, ll m){if(b == 0) return 1ll;ll ret = expo(a, b/2, m);ret = (ret%m * ret%m)%m;if(b%2) ret = (ret*a)%m;return ret;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}

ll N = 2000005;
ll fact[2000005], invfact[2000005];

void precompute()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
    invfact[N-1]=mminvprime(fact[N-1], MOD);
    for(int i=N-2;i>0;i--)
    {
        invfact[i]=invfact[i+1]*(i+1);
        invfact[i]%=MOD;
    }
}


ll nCr(ll x, ll y)
{
    if(x == y) return 1;
    if(y>x)return 0;
    ll int num=fact[x];
    num*=invfact[y];
    num%=MOD;
    num*=invfact[x-y];
    num%=MOD;
    return num;
}

void solve(int tc){
    cout << nCr(5, 2) << endl;
}


int main(){
    int tc = 1, cas_no = 0;
    precompute();
    cout << fixed << setprecision(10);
    // scanf("%d", &tc);
    // cin >> tc;
    while(tc--){++cas_no;solve(cas_no);}return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN   1001

ll n, m, a, b, k, x, y, w, h, p, l, t, r;

vector<ll> adj[MAXN], adj_rev[MAXN];
bool vis[MAXN];

vector<ll> order, component;

void dfs1(ll node){
	vis[node] = 1;
	for(auto child:adj[node]){
		if(!vis[child]){
			dfs1(child);
		}
	}
	order.push_back(node);
}

void dfs2(ll node){
	vis[node] = 1;
	component.push_back(node);
	for(auto child:adj_rev[node]){
		if(!vis[child]){
			dfs2(child);
		}
	}
}



void solve(){
	bool ok = true, can = false;
	ll tot = 0, mn = LLONG_MAX, mx = LLONG_MIN, q;
	ll sum = 0, sum1 = 0;
	ll edgeCount;
	cin >> n >> edgeCount;
	for(int i=1;i<=n;i++) vis[i] = 0;
	for(int i=0;i<edgeCount;i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj_rev[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs1(i);
	}
	for(int i=1;i<=n;i++) vis[i] = 0;
	reverse(order.begin(), order.end());
	
	for(auto u:order){
		if(!vis[u]){
			component.clear();
			dfs2(u);
			for(auto f:component){
				cout << f <<" ";
			}
			cout << endl;
		}
	}

}
 
int main(){
	ios::sync_with_stdio(0);
	int tc = 1;
	// cin >> tc;
	// cout << setprecision(30);
	while(tc--){
		solve();
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m, a, b, k, x, y, w, h, p, l, t, r;

/* Kosaraju Algorithm for
   finding strongly connected components
*/

ll nodeCount, edgeCount;
ll processing_time[1001];
vector<ll> adj[1001];
vector<ll> reversed[1001];
vector<pair<ll, ll>> vt;
bool visited[1001];
ll current_time = 0;

void dfs(ll node){ // this dfs find the outtime of a node
	visited[node] = 1;
	for(auto child:adj[node]){
		if(!visited[child]){
			current_time++;
			dfs(child);

		}
	}
	current_time++;
	processing_time[node] = current_time; 
}

void dfs2(ll node){// this dfs finds connected components on reversed edges
	cout << node <<" ";
	visited[node] = 1;
	for(auto child:reversed[node]){
		if(!visited[child]){
			dfs2(child);
		}
	}
}


void solve(){
	bool ok = true, can = false;
	ll tot = 0, mn = LLONG_MAX, mx = LLONG_MIN, q;
	ll sum = 0, sum1 = 0;
	
	cin >> nodeCount >> edgeCount;
	for(int i=0;i<edgeCount;i++){
		cin >> a >> b;
		adj[a].push_back(b);
		reversed[b].push_back(a);
	}

	for(int i=1;i<=nodeCount;i++){
		if(!visited[i]){
			current_time++;
			dfs(i);
		}
	}
	for(int i=1;i<=nodeCount;i++){
		vt.push_back({processing_time[i], i});
	}
	sort(vt.rbegin(), vt.rend());
	for(int i=1;i<=nodeCount;i++){
		visited[i]=0;
	}
	for(int i=0;i<nodeCount;i++){
		if(!visited[vt[i].second]){
			dfs2(vt[i].second);
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

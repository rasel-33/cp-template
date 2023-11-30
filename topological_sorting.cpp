#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl  '\n'
#define MOD  1073741824

ll n, m, a, b, k, x, y, w, h;
string s, sa, sb;


/////////////  Topological Sorting of a Directed Graph ////////////// 
vector<ll> adj[1001];
vector<ll> tps; 
vector<ll> visited(1001, 0);
bool cycle = 0;

void tpsDFS(ll node){
	visited[node] = 1;
	for(int i=0;i<adj[node].size();i++){
		if(visited[adj[node][i]]==1){
			cycle = 1;
			tpsDFS(adj[node][i]);
		}
		else if(visited[adj[node][i]]==0){
			tpsDFS(adj[node][i]);
		}
	}
	visited[node] = 2;
	tps.push_back(node);
}

vector<ll> topologicalSort(ll nodeCount){//call this function to
	for(ll i=1;i<=nodeCount;i++){        //get topological sort
		if(visited[i]==0){			     //of a directed graph
			tpsDFS(i);                   //if it returns an
		}							     //empty vector that means
	}								     //the graph contains a cycle
	vector<ll> vt;
	if(!cycle){
		reverse(tps.begin(), tps.end());
		vt = tps;
	}
	tps.clear();
	return vt;
}



void solve(){
	bool ok = true, can = false;
	ll tot = 0, mn = LLONG_MAX, mx = LLONG_MIN, q;
	ll nodeCount, edgeCount;
	cin >> nodeCount >> edgeCount;
	for(int i=0;i<edgeCount;i++){
		cin >> a >> b;
		adj[a].push_back(b);
	}

	vector<ll> ordering = topologicalSort(nodeCount);
	if(ordering.size()==0){
		cout << "The Graph contains a cycle" << endl;
	}
	else{
		for(auto e:ordering){
			cout << e << " ";
		}
		cout << endl;
	}
	
}
 
int main(){
	ios::sync_with_stdio(0);
	int tc = 1;
	// cin >> tc;
	while(tc--){
		solve();
	}
	return 0;
}

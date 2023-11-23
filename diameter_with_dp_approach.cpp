#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m, a, b, k, x, y;
string sa, sb;
vector<ll> adj[10001];

// Diameter of a tree using Dynamic Programming
// maxLength(x) contains the highest path, remarking x as the highest node of the path
// max(maxLenth(x)) will give you the Diameter of the Tree

ll toLeaf[10001];
ll maxLength[10001];
void DFS(ll node, ll par){
	toLeaf[node] = 0;
	ll mx1 = 0, mx2 = 0;
	for(auto child:adj[node]){
		if(child == par) continue;
		DFS(child, node);
		toLeaf[node] = max(toLeaf[node], toLeaf[child]+1);
		if(toLeaf[child]+1>mx1){
			mx1 = toLeaf[child]+1;
		}
		else if(toLeaf[child]+1>mx2){
			mx2 = toLeaf[child]+1;
		}
	}	
	maxLength[node] = mx1 + mx2;
}


// individual test case
void solve(){
	bool ok = true, can = false;
	ll tot = 0, mn = LLONG_MAX, mx = LLONG_MIN; 
	cin >> n;
	for(int i=0;i<n-1;i++){
		cin  >>  x  >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	DFS(1, -1);
	ll diameter = 0;
	for(int i=1;i<=n;i++){
		cout << i <<" toLeaef -> "<<toLeaf[i]<<endl;
	}

	for(int i=1;i<=n;i++){
		cout << i <<" maxLength -> "<<maxLength[i]<<endl;
		diameter = max(diameter, maxLength[i]);
	}
	cout << "Diameter -> " << diameter << endl;


}
 
int main(){
	int tc = 1;
	// cin >> tc;
	while(tc--){
		solve();
	}
	return 0;
}

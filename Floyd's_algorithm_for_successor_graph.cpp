#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll n;

/*
Floyd's Algorithm to find cycle length 
and first node of the cycle in the
successor graph.
*/
ll succ[10005];

ll find_length(ll x){//find length of the cycle in which component the node belongs to
	ll a = succ[x];
	ll b = succ[succ[x]];
	while(a!=b){
		a = succ[a];
		b = succ[succ[b]];
	}
	a = x;
	while(a!=b){
		a = succ[a];
		b = succ[b];
	}
	cout << "First Node of the cycle " << a << endl;

	b = succ[a];
	ll length = 1;
	while(a!=b){
		b = succ[b];
		length++;
	} 
	return length;
}


void solve(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> succ[i];
	}

	cout << find_length(1) << endl;
}
 
int main(){
	ios::sync_with_stdio(0);
	int tc = 1;
	while(tc--){
		solve();
	}
	return 0;
}

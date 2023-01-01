#include<bits/stdc++.h>
using namespace std ;


int main() {

	vector<vector<int>> adj(5) ;

	for(int i=0; i<5; i++) {
		int u, v ;
		cin >> u >> v ;
		u--, v-- ;
		adj[u].push_back(v) ;
		adj[v].push_back(u) ;
	}


	int x, y ;
	cin >> x >> y ;

	bool visited[5] = {0} ;
	function<bool(int a, int b)> dfs = [&](int x, int y) {

		if(x == y) {
			return true ;
		}

		if(visited[x] == true) return false ;
		visited[x] = true ;

		for(auto Y:adj[x]) {
			if(dfs(Y, y)) {
				return true ;
			}
		}

		return false ;
	};

	cout << dfs(x, y) << "\n" ;
}

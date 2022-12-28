#include<bits/stdc++.h> 
using namespace std ;

#define ll int64_t 

int n,m,i,j,x ;
const int mxN = 1010 ;
vector<vector<int>> a(mxN, vector<int> (mxN)) ;




bool Valid(int i, int j, int M, bool vis[][mxN], vector<vector<int>> & a, int parent) {
	if(i < 0 or j < 0 or i >= n or j >= m or abs(a[i][j] - parent) > M or vis[i][j]) {
		return false ;
	}
	if(i == n-1 and j == m-1) {
		return true ;
	}

	vis[i][j] = true ;

	if(Valid(i+1, j, M, vis, a, a[i][j])) return true ;
	if(Valid(i-1, j, M, vis, a, a[i][j])) return true ;
	if(Valid(i, j+1, M, vis, a, a[i][j])) return true ;
	if(Valid(i, j-1, M, vis, a, a[i][j])) return true ;

	return false ;

}
int MinPath(vector<vector<int>> & a) {
	int L = 0, R = 1e7 ;
	int res = a[0][0] ;
	while(L <= R) {
		int M = ( L +  R ) >> 1 ;
		bool vis[mxN][mxN] = {0} ;
		if(Valid(0, 0, M, vis, a, a[0][0])) {
			res = M ;
			R = M - 1 ;
		}
		else {
			L = M + 1 ;
		}

	}
	return res ;
}
int main() {


	cin >> n >> m ;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> a[i][j] ;
		}
	}

	cout << MinPath(a) << "\n" ;


	
	return 0 ;



}
/*
Sample :
3 3 
1 2 1 
2 8 2
2 4 2 
Ans -> 1 
*/

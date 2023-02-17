/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
// https://codeforces.com/contest/27/problem/A
// Accepted
#include <bits/stdc++.h>
using namespace std ;
using i64 = long long;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "->"; god(x); cerr << "\n";
#else 
#define debug(x)
#endif 
void god(i64 UWU) { cerr << UWU;}
void god(int UWU) { cerr << UWU;}
void god(string UWU) { cerr << UWU;}
void god(char UWU) { cerr << UWU;}
void god(double UWU) {cerr << UWU;}
void god(long double UWU) {cerr << UWU;}
template<class T> void god(vector<T> V) {cerr << "["; for(T I:V) {god(I); cerr << " ";} cerr << "]";}

int N, test;
vector<bool> vis(3010);
void solve() {
	cin >> N;
	
	for(int i=0; i<N; i++) {
		cin >> test;
		vis[test] = 1;
	}

	for(int i=1; i<=3010; i++) {
		if(!vis[i]) {
			cout << i << "\n";
			return;
		}
	}
}
int main() {

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

   	solve();
    return 0;
}

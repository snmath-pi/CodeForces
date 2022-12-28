//#include<bits/stdc++.h>
#include <algorithm>
#include <list> 
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std ;
#define ll long long 
#define ld long double
#define all(x) (x).begin() , (x).end()
#define minel *min_element(all(x)) 
#define maxel *max_element(all(x)) 
#define sz(x) (x).size() 
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ROF(i,b,a) for(int i=a-1;i>=b;--i)
#define vi vector<int> 
#define vb vector<bool> 
#define vl vector<long long>
#define vs vector<string>
#define vc vector<char> 
#define pi pair<int,int> 
#define pll pair<ll,ll> 
#define pc pair<char,char> 
#define pic pair<int,char> 
#define f first 
#define s second 
#define str string
#define pb push_back
#define lb lower_bound
#define ub upper_bound 
#define fastio std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr) ;
/******************************************************************************/
ll MOD = 1e9 + 7 ;
// ll MOD = 998244353 ; 
ll binpow(ll a, ll b) {ll res = 1;while (b > 0) {if (b & 1){res = res * a ;}a = a * a;b >>= 1;}return res;}

ll int_sqrt (ll x) {ll ans = 0;for (ll k = 1LL << 30; k != 0; k /= 2) {if ((ans + k) * (ans + k) <= x) {ans += k;}}return ans;}

int digitCount(ll n){ll cnt(0) ;while(n){cnt++ ;n /= 10 ;}return cnt ;}

bool isPrime(ll n){if(n == 1) return false ;for(ll i=2; i*i<=n; i++){if(n%i==0)return false ;}return true;}

int cuberoot(int n){double a  = floor(pow(n , 1/3.0) + 1e-6); double dx  = (n - a* a * a) / 3.0 / a / a ;return (a + dx) ;}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/******************************************************************************/
const int mxN = 1e5 ;
vector<int> adj[mxN] ;
vector<bool> vis(mxN, 0) ;
int n, m, x ;
int bfs(int root, int x)  {
	if(x > n or adj[x].size() == 0) {
		return -1 ;
	}
	int level = 0 ;
	queue<int> q ;
	q.push(root) ;
	vis[root] = true ;
	while(!q.empty()) {
		int S = sz(q) ;
		while(S--) {
			int N = q.front() ;
			q.pop() ;

			if(N == x) {
				return level ;
			}
			for(auto Y:adj[N]) {
				if(!vis[Y]) {
					q.push(Y) ;
					vis[Y] = 1 ;
				}
			}
		}
		level++ ;
	}
	return -1 ;


}
void math_pi() {
	
	cin >> n >> m >> x;
	for(int i=0; i<m; i++) {
		int u, v; 
		cin >> u >> v ;
		adj[u].pb(v) ;
		adj[v].pb(u) ;
	}
	cout << bfs(0, x) ;

	
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    fastio
    int t = 1 ;
    // std::cin >> t;
    while(t--) {
        math_pi() ;
    }
}

// input : 4 4 3 
0 1
0 2
1 3
2 4

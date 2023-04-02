#include <bits/stdc++.h>
//  https://codeforces.com/problemset/problem/630/K
#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vl vector<long long>
#define pi pair<int, int> 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;
 
ll t, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	// 1 is always the answer
	// all prime numbers > 7 are always the answer
	// 2 covers all even numbers from 1 -> n, all numbers covered by 4, 6, 8, 10 so these 4 are redundant
	// 3, 5, 7, 9 are only odds left
	// 5 covers all odds ending with 5 
	// axiom:? 3, 5, 7, 9 can cover all non-prime odd integers b/w [1, n];
	// the answer is all primes b/w 1->n - 4 + 1

	ll cnt = n / 2 + n / 3 + n / 5 + n / 7 - n / (2 * 3) - n / (2 * 5) - n / (2 * 7) - n / (3 * 5) - n / (3 * 7) - n/(5 * 7) + n / (2 * 3 * 5) + n / (2 * 3 * 7) + n / (2 * 5*7) + n / (3 * 5 * 7) - n / (2 * 3 * 5 * 7);
	cout << n - cnt;

}

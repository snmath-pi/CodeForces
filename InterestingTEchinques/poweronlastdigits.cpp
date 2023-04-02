// https://codeforces.com/problemset/problem/630/L
#include <bits/stdc++.h>
 
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
 
int t, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vi a;
	t = n;
	while(t) {a.pb(t%10); t/=10;};
	reverse(all(a));
	vi b(5);
	b[0] = a[0], b[1] = a[2], b[2] = a[4], b[3] = a[3], b[4] = a[1];

	map<int, vi> cyclicity_to_one;
	rep(i, 10) {
		if(!i or i == 1 or i == 5 or i == 6) {
			rep(j, 5) cyclicity_to_one[i].pb(i);
		} else {
			if(i == 2) {
				cyclicity_to_one[i].pb(2);
				cyclicity_to_one[i].pb(4);
				cyclicity_to_one[i].pb(8);
				cyclicity_to_one[i].pb(6);
				cyclicity_to_one[i].pb(2);
			}
			if(i == 3) {
				cyclicity_to_one[i].pb(3);
				cyclicity_to_one[i].pb(9);
				cyclicity_to_one[i].pb(7);
				cyclicity_to_one[i].pb(1);
				cyclicity_to_one[i].pb(3);
			}if(i == 4) {
				cyclicity_to_one[i].pb(4);
				cyclicity_to_one[i].pb(6);
				cyclicity_to_one[i].pb(4);
				cyclicity_to_one[i].pb(6);
				cyclicity_to_one[i].pb(4);
			}if(i == 7) {
				cyclicity_to_one[i].pb(7);
				cyclicity_to_one[i].pb(9);
				cyclicity_to_one[i].pb(3);
				cyclicity_to_one[i].pb(1);
				cyclicity_to_one[i].pb(7);
			}if(i == 8) {
				cyclicity_to_one[i].pb(8);
				cyclicity_to_one[i].pb(4);
				cyclicity_to_one[i].pb(2);
				cyclicity_to_one[i].pb(6);
				cyclicity_to_one[i].pb(8);
			}if(i == 9) {
				cyclicity_to_one[i].pb(9);
				cyclicity_to_one[i].pb(1);
				cyclicity_to_one[i].pb(9);
				cyclicity_to_one[i].pb(1);
				cyclicity_to_one[i].pb(9);
			}

		}
	}
	vi ans;
	// ans[4] = cyclicity_to_one[b[4]][4];
	// // okay for 10's digit b[3] & b[4] remain fixed during multiplication
	// int sum1 = 0;
	// int left = 0;
	// int cnt = 4;
	// while(cnt) {
	// 	int val =  (b[3] * cyclicity_to_one[2][4-cnt] + )
	// 	cnt--;
	// }

	ll lst = 0;
	rep(i, 5) {
		lst += (b[i] * powl(10, 4- i));
	}
	const int m = 1e5;
	ll ret = 1;
	rep(i, 5) {
		ret = ret * lst % m;
	}
	if(!ret) {
		cout << "00000";
	} else cout << ret;
	// // rep(i, 5) cout << ans[i];

	// while(ret) {ans.pb(ret%10); ret/=10;}; reverse(all(ret));
	int x = 124;
	ret = 1;
	rep(i, 4) {
		ret = ret * x % 100;
	}
	cout << ret;



}

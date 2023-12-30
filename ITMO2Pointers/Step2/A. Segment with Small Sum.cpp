#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long

const int N = 1e5 + 10;
const int LG = 8;
ll A[N];
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	
	int n; ll S;
	cin >> n >> S;
	for(int i=0; i<n; i++) {
		cin >> A[i];
	}	

	ll res = 0;
	for(ll x = 0, r = 0, l = 0; r < n; r++) {
		x += A[r];
		while(x > S) {
			x -= A[l++];
		}
		if(x <= S) {
			res = max(res, r - l + 1);
		}
	}

	cout << res;
}

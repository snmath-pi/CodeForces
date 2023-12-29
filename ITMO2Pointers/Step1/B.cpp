#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long


int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);

	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	for(int i=0; i<m; i++) {
		cin >> b[i];
	}


	for(int l = 0, r = 0; l < n || r < m; ) {
		if(r == m || l < n && a[l] < b[r]) {
			l++;
		} else {
			r++;
			cout << l << ' ';
		}
	}


}

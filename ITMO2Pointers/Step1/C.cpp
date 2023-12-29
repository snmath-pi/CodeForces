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

	long long res = 0, c1 = 1, c2 = 1;
	for(int l = 0, r = 0; l < n && r < m; ) {
		if(a[l] < b[r]) {
			l++;
		} else {
			if(a[l] > b[r]) r++;
			else {
				l++;
				for(; l < n && a[l] == a[l-1];) {l++, c1++;}
				r++;
				for(; r < m && b[r] == b[r-1];) {r++, c2++;}
			   	res += c1 *1ll*c2;
				c1 = c2 = 1;	
			}
		}
	}

	cout << res << '\n';


}

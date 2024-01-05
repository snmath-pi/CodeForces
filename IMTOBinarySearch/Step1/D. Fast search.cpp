#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);

	int n, k;
	cin >> n;
	vector<int> a(n);

	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(begin(a), end(a));

	auto find = [&](int val) {
		int l = -1, r = n;
		while(r > l + 1) {
			int m = l + r >> 1;
			if(a[m] <= val) l = m;
			else r = m;
		}
		return l+1;
	};
	auto findvv = [&](int val) {
		int l = -1, r = n;
		while(r > l + 1) {
			int m = l + r >> 1;
			if(a[m] < val) l = m;
			else r = m;
		}
		return l+1;
	};
	cin >> k;
	for(int i=0; i<k; i++) {
		int l, r; cin >> l >> r;
		if(l > r) swap(l, r);
		l = findvv(l);
		r = find(r);
		cout << r - l  << ' ';
	}
}

#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);

	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	auto find = [&](int val) {
		int l = -1, r = n;
		while(r > l + 1) {
			int m = l + r >> 1;
			if(a[m] == val) return true;
			else if(a[m] < val) l = m;
			else r = m;
		}
		return false;
	};

	for(int i=0; i<k; i++) {
		int x; cin >> x;
		cout << (find(x) ? "YES":"NO") << '\n';
	}
}

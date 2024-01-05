#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;

	vector<long double> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	auto good = [&](long double val) {
		long long tot = 0;
		for(int i=0; i<n; i++) {
			tot += (long long) (a[i] / val);
		}
		return tot >= k;
	};
	long double l = 0, r = 1e12;
	for(int iter = 0; iter <= 100; iter++) {
		long double m = (l + r) / 2;
		if(good(m)) {
			l = m;
		} else r = m;
	}

	cout << setprecision(6) << fixed << l << '\n';
}

#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);

	long long w, h, n;
	cin >> w >> h >> n;
	long long l = -1, r = 2e18;
	auto good = [&](long long val) {
		__int128 X = val / h;
		X *= val/w;
		return X >= n;
	};
	while(r > l + 1) {
		long long m = l + r >> 1;
		if(good(m)) {
			r = m;
		} else l = m;
	}
	cout << r << '\n';
}

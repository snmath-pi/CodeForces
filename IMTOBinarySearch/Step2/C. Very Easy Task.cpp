#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	
	int n, x, y;
	cin >> n >> x >> y;
	if( x > y ) swap(x, y);
	long long l = -1, r = 1e12;
	
	auto good = [&](long long val) {
		if(val < x) return false;
		val -= x; long long tot = 1;
		tot += val / x; tot += val / y;
		return tot >= n;
	};
	while(r > l + 1) {
		long long m = l + r >> 1;
		if(good(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	
	cout << r << '\n';
}

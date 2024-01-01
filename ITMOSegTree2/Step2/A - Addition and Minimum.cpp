#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

const int N = 1e5 + 10;
vector<ll>A;
int n, m;

struct seg {
	vector<long long> ops;
	vector<long long> mins;
	int size;


	seg(int n) {
		for(size = 1; size < n; size <<= 1) {};
		ops.resize(2*size);
		mins.assign(2*size, 0);
	}
	void add(int x, int lx, int rx, int l, int r, int v) {
		if(lx>=r || rx<=l) return;
		if(lx>=l && rx <= r) {
			ops[x] += v;
			mins[x] += v;
			return;
		}

		int m = lx + rx >> 1;
		add(2*x + 1, lx, m, l, r, v);
		add(2*x + 2, m, rx, l, r, v);
		mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]) + ops[x];
	}

	long long getmin(int x, int lx, int rx, int l, int r) {
		if(lx>=r || rx <= l) return LLONG_MAX;
		if(lx >= l && rx <= r) {
			return mins[x];
		}
		int m  = lx + rx >> 1;
		long long mn1 = getmin(2 * x + 1, lx, m, l, r);
		long long mn2 = getmin(2 * x + 2, m, rx, l, r);
		return min(mn1, mn2) + ops[x];
	}
	long long getmin(int l, int r) {
		return getmin(0, 0, size, l, r);
	}
	void add(int l, int r, int v) {
		return add(0, 0, size, l, r, v);
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;

	seg st(n);

	for(int i=0; i<m; i++) {
		int type; cin >> type;
		if(type == 1) {
			int l, r, v; cin >> l >> r >> v;
			st.add(l, r, v);
		} else {
			int l, r; cin >> l >> r;

			cout << st.getmin(l, r) << '\n';
		}
	}
	
}

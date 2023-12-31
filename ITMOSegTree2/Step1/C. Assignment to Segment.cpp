#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

const int N = 1e5 + 10;
vector<ll>A;
int n, m;

struct seg {
	vector<long long> ops;
	int size;


	seg(int n) {
		for(size = 1; size < n; size <<= 1) {};
		ops.resize(2*size);
	}
	const long long NO_OP = LLONG_MAX;
	long long operation(long long x, long long y) {
		if(y == NO_OP) return x;
		return y;
	}

	void apply_op(long long &a, long long b) {
		a = operation(a, b);
	}
	
	void propogate(long long x, int lx, int rx) {
		if(rx - lx == 1) return;
		apply_op(ops[2 * x + 1], ops[x]);
		apply_op(ops[2 * x + 2], ops[x]);
		ops[x] = NO_OP;
	}
	void add(int x, int lx, int rx, int l, int r, int v) {
		propogate(x, lx, rx);
		if(lx>=r || rx<=l) return;
		if(lx>=l && rx <= r) {
			apply_op(ops[x], v);
			return;
		}

		int m = lx + rx >> 1;
		add(2*x + 1, lx, m, l, r, v);
		add(2*x + 2, m, rx, l, r, v);
	}
	
	void add(int l, int r, int v) {
		return add(0, 0, size, l, r, v);
	}
	long long get(int x, int lx, int rx, int i) {
		propogate(x, lx, rx);
		if(rx - lx == 1) {
			return ops[x];
		}
		int m = lx + rx >> 1;
		long long res;
		if(i < m) {
			res = get(2 * x + 1, lx, m, i);
		} else {
			res = get(2 * x + 2, m, rx, i);
		}
		return res;
	}
	long long get(int i) {
		return get(0, 0, size, i);
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
			int i; cin >> i;

			cout << st.get(i) << '\n';
		}
	}
	
}

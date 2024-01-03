#include<bits/stdc++.h>
using namespace std;
// associative general operations
// such as (they should be distributive) -> (a X v) ~ (b X v) => (a ~ b) X v
// X(ops) query(ops)
// *      +
// &      |
// +      min, max
// +      + ( a + B) + (c + B) != (a + c) + B (
// actually it can be done by multiplying B with length of the segement

const int mod = 1e9 + 7;
struct seg {
	vector<long long> values;
	vector<long long> ops;
	int size;
	
	long long NEUTRAL_ELEMENT = 0;
	long long modify_op(long long a, long long b) {
		return a * b % mod;
	}
	
	long long calc_op(long long a, long long b) {
		return (a + b) % mod;
	}
	void apply_mod_op(long long &a, long long b) {
		a = modify_op(a, b);
	}

	void build(int x, int lx, int rx) {
		if(rx == lx + 1) {
			values[x] = 1;
			return;
		}
		int m = lx + rx >> 1;
		build(2 * x + 1, lx, m);
		build(2 * x + 2, m ,rx);
		values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
	}
	seg(int n) {
		for(size = 1; size < n; size <<= 1){}
		values.resize(2*size);
		ops.assign(2*size, 1);
		build(0, 0, size);
	}
	
	long long calc(int x, int lx, int rx, int l, int r) {
		if(lx>=r || rx<=l) return NEUTRAL_ELEMENT;
		if(lx>=l && rx <= r) {
			return values[x];
		}
		int m = lx + rx >> 1;
		long long val1 = calc(2 * x + 1, lx, m, l, r);
		long long val2 = calc(2 * x + 2, m, rx, l, r);
		long long res = calc_op(val1, val2);
		apply_mod_op(res, ops[x]);
		return res;
	}
	long long calc(int l, int r) {
		return calc(0, 0, size, l, r);
	}
	void modify(int x, int lx, int rx, int l, int r, int v) {
		if(lx>=r || rx <= l) return;
		if(lx>=l && rx<=r) {
			apply_mod_op(ops[x], v);
			apply_mod_op(values[x], v);
			return;
		}
		int m = lx + rx >> 1;
		modify(2 * x + 1, lx, m, l, r, v);
		modify(2 * x + 2, m, rx, l, r, v);
		values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
		apply_mod_op(values[x], ops[x]);
	}
	void modify(int l, int r, int v) {	
		return modify(0, 0, size, l, r, v);
	}
};
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	seg st(n);
	
	for(int i=0; i<m; i++) {
		int type; cin >> type;
		if(type==1) {
			int l, r, v; cin >> l >> r >> v;
			st.modify(l, r, v);
		}
		else {
			int l, r; cin >> l >> r;
			cout << st.calc(l, r) << '\n';
		}
	}
}

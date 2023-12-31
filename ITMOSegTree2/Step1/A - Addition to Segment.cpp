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

	void add(int x, int lx, int rx, int l, int r, int v) {
		if(lx>=r || rx<=l) return;
		if(lx>=l && rx <= r) {
			ops[x] += v;
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
		return res + ops[x];
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

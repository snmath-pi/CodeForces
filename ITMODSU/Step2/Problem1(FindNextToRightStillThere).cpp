#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

struct dsu {
	vector<int> p, sz;
	dsu(int n) {
		p.resize(n+1); sz.resize(n+1);
		for(int i=0; i<=n; i++) {
			p[i] = i; sz[i] = 1;
		}
	}

	int get(int a) {
		return p[a] = (p[a] == a ? a : get(p[a]));
	}

	void unite(int a, int b) {
		a = get(a); b = get(b);
		if(a == b) return;
		p[a] = b;
		sz[b] += sz[a];
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("closing.in", "r", stdin);
	//freopen("closing.out", "w", stdout);\
	
	int n, m;
	cin >> n >> m;
	dsu d(n);
	for(int i=0; i<m; i++) {
		char c; cin >> c;
		int x; cin >> x;--x;
		if(c=='-') {
			d.unite(x, x+1);
		} else {
			x = d.get(x);
			cout << (x==n?-1:x+1) << '\n';
		}
	}
}	


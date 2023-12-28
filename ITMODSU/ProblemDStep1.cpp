#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
int val = 0;
struct dsu {
	vector<int> p, sz;
	vector<int> score, extra;
	dsu(int n) {
		p.resize(n+1); sz.resize(n+1);
		score.resize(n+1); extra.resize(n+1);
		for(int i=0; i<=n; i++) {
			p[i] = i; sz[i] = 1;
		}
	}
	int get(int a) {
		return p[a] == a ? a : get(p[a]);
	}
	int S(int a) {
		return p[a] == a ? score[a] : (score[a] - extra[a] + S(p[a]));
	}
	void unite(int a, int b) {
		a = get(a); b = get(b);
		if(a == b) return;
		if(sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		extra[b] = score[a];
	}
};
struct item {
	string s; int x, y;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("closing.in", "r", stdin);
	//freopen("closing.out", "w", stdout);\
	
	int n, m, q;
	cin >> n >> m >> q;
	dsu d(n);
	vector<item> a;
	vector<vector<int>> g(n);

	for(int i=0; i<m; i++) {
		int u, v; cin >> u >> v; --u, --v;
		g[u].push_back(v); g[v].push_back(u);
	}
	for(int i=0; i<q; i++) {
		string s; cin >> s;
		int x, y; cin >> x >> y;
		--x, --y;
		a.push_back({s, x, y});
	}
	reverse(begin(a), end(a));
	vector<string> res;
	for(auto &x: a) {
		if(x.s == "cut") {
			d.unite(x.x, x.y);
		} else {
			res.push_back((d.get(x.x) == d.get(x.y) ? "YES":"NO"));
		}
	}

	reverse(begin(res), end(res));
	for(auto &x: res) {
		cout << x << '\n';
	}
}	


#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

struct dsu {
	vector<int> p, sz;
	vector<pair<int, int>> query;
	int comp;
	dsu(int n) {
		comp = n;
		query.resize(n);
		p.resize(n); sz.resize(n, 1);
		for(int i=0; i<n; i++) {
			p[i] = i;
			query[i] = {i, i};
		}
	}

	int get(int a) {
		return p[a] = (p[a]==a?a:get(p[a]));
	}

	void unite(int a, int b) {
		a = get(a), b = get(b);
		if(a==b) return;
		if(sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		query[a].first = max(query[a].first, query[b].first);
		query[a].second = min(query[a].second, query[b].second);
		comp--;
	}
};
int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	dsu d(n);

	for(int i=0; i<q; i++) {
		string s; cin >> s;
		if(s=="union") {
			int a, b;
			cin >> a >> b;
			--a, --b;
			d.unite(a, b);
		} else {
			int x; cin >> x; --x; x = d.get(x);
			cout << d.query[x].second+1 << ' ' << d.query[x].first+1 << ' '<< d.sz[x]<< '\n';
			//cout << d.sz[x] << '\n';
		}
	}
}

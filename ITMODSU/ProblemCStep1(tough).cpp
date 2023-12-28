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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("closing.in", "r", stdin);
	//freopen("closing.out", "w", stdout);\
	
	int n, m;
	cin >> n >> m;
	dsu d(n);

	for(int i=0; i<m; i++) {
		string s; cin >> s;
		if(s == "join") {
			int x, y; cin >> x >> y;
			d.unite(--x, --y);
		}
		else if(s == "add") {
			int x, y; cin >> x >> y; --x;
			x = d.get(x);
			d.score[x] += y;
		}

		else {
			int x; cin >> x; --x; 
			cout << d.S(x) << '\n';	
		}
	}
}	


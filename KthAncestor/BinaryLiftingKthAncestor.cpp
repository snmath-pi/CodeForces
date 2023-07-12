// https://www.hackerearth.com/problem/algorithm/whos-your-daddy/

#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int depth[100005];
int father[100005][19];
int LN = 18;
void dfs(int node, int parent) {
    father[node][0] = parent;
    depth[node] = depth[parent] + 1;
    for(auto &x: g[node]) {
        if(x != parent) dfs(x, node);
    }
}
int main() {
    int n; cin >> n;
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    depth[0] = -1;
    dfs(1, 0);
    for(int j=1; j<=18; j++) {
        for(int i=1; i<=n; i++) {
            father[i][j] = father[father[i][j-1]][j-1];
        }
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        int p, k;
        cin >> p >> k;
        if(depth[p] < k) {
            cout << -1 << '\n';
        } else {
            for(int i=0; i<LN; i++) {
                if((k >> i) & 1) {
                    p = father[p][i];
                }
            }
            cout << p << '\n';
        }
    }

    
}

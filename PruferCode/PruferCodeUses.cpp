// PRUFER CODE NON LINEAR O(NLOGN) USING SETS
#include<bits/stdc++.h>
using namespace std;
vector<int> prufer_code(vector<vector<int>> &g) {
    int n = g.size();
    set<int> leafs;
    vector<int> degree(n);
    for(int i=0; i<n; i++) {
        degree[i] = (int) g[i].size();
        if(degree[i] == 1) leafs.insert(i);
    }

    vector<int> code(n-2);
    vector<int> killed(n);
    for(int i=0; i<n-2; i++) {
        auto it = *leafs.begin();
        leafs.erase(it);
        killed[it] = 1;
        int v = -1;
        for(auto &to: g[it]) {
            if(!killed[to]) {
                v = to;
            }
        }
        code[i] = v;
        if(--degree[v] == 1) leafs.insert(v);
    }

    return code;
}


// TO FIND PRUFER CODE IN o(N);

vector<int> prufer_code_linear(vector<vector<int>> &g) {
    int n = g.size();
    vector<int> parent(n);
    parent[n-1] = -1;

    function<void(int, int)> dfs = [&](int me, int p) {
        for(int &to: g[me]) {
            if(to != p) {
                parent[to] = me;
                dfs(to, me);
            }
        }
    };
    dfs(n-1, -1);
    vector<int> degree(n);

    int ptr = -1;
    for(int i=0; i<n; i++) {
        degree[i] = g[i].size();
        if(degree[i]==1 && ptr == -1) {
            ptr = i;
        }
    }

    vector<int> code(n-2);

    int leaf = ptr;

    for(int i=0; i<n-2; i++) {
        int next = parent[leaf];
        code[i] = next;
        if(--degree[next] && next < ptr) {
            leaf = next;
        } else {
            ptr++;
            while(degree[ptr] != 1) ptr++;
            leaf = ptr;
        }
    }

    return code;
}


// TO RECOVER THE TREE IN O(NLOGN);

vector<pair<int, int>> prufer_decode(vector<int> const &code) {
    int n = code.size() + 2;
    vector<int> degree(n, 1);
    for(auto i: code) {
        degree[i]++;
    }

    set<int> leaves;
    for(int i=0; i<n; i++) {
        if(degree[i] == 1) {
            leaves.insert(i);
        }
    }

    vector<pair<int, int>> edges;
    for(int v: code) {
        int leaf = *leaves.begin();
        leaves.erase(leaf);

        edges.emplace_back(leaf, v);
        if(--degree[v]==1) {
            leaves.insert(v);
        }
    }

    edges.emplace_back(*leaves.begin(), n-1);
    return edges;
}




// TO FIND NUMBER OF WAYS TO MAKE THE GRAPH OF K COMPONENTS CONNECTED
// BASICALLY IF A GRAPH HAS K COMPONENTS OF SIZES S1,S2, ... SK
// IT'S GIVEN BY S1 * S2 * ... * SK * (N ^ K-2) VIA PRUFER CODE MULTINOMIAL
typedef long long ll;
const int N = 1e5 + 10;
vector<int> g[N], vis(N);

int dfs(int me) {

    vis[me] = 1;
    int cnt = 1;
    for(auto &to: g[me]) {
        if(!vis[to]) {
            cnt+=dfs(to);
        }
    }
    return cnt;
}
ll qpow(ll x, ll y, ll mod) {
    ll ans = 1; for(; y; y>>=1) {
        if(y & 1) ans = ans * x % mod;
        x = x * x % mod;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v; 
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    vector<ll> sz;
    int comp = 0;
    ll res = 1;
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            comp++;
            res = res * dfs(i) % k;
        }
    }
    
    if(comp==1) {
        cout << 1 % k << '\n';
        return 0;
    }
    cout << res * qpow(n, comp-2, k) % k << '\n';

}



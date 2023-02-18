/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
// https://codeforces.com/gym/102694/problem/A
// Accepted~ Saksham Negi
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 mxN = 400000;
i64 N, u, v;
vector<bool> vis(mxN);
vector<vector<i64>> edge(mxN);
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> N;
    for(i64 i=0; i<N-1; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    i64 diameter = -1e9;
    i64 far_node;
    function<void(i64, i64)> dfs = [&](i64 i, i64 curr_count) {
        vis[i] = 1;
        curr_count++;
        for(auto x:edge[i]) {
            if(!vis[x]) {
                if(curr_count >= diameter) {
                    far_node = x;
                    diameter = curr_count;
                }
                dfs(x, curr_count);
            }
        }
    };
    dfs(1, 0);
    vis.assign(mxN, 0);
    dfs(far_node, 0);
    cout << (diameter == -1e9?0:3 * 1LL * diameter) << "\n";
    return 0;
}

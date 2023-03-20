#include <bits/stdc++.h>
//https://docs.google.com/document/d/1zuw8hBXHsiTYTH8u986fQhn8TWfpOk9BQBIRH3lo_W8/edit
#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vl vector<long long>
#define pi pair<int, int> 
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;
 
int t, n;

ll dp[21][1<<21];
int c[21][21];
ll solve(int i, int mask, int& n) {
    if(i == n) return 0;
    if(dp[i][mask] != -1) return dp[i][mask];

    ll ans = 1e12;
    for(int j=0; j<n; j++) {
        if(mask & (1 << j)) 
            ans = min(ans, c[j][i] + solve(i + 1, (mask ^ (1 << j)), n));
    }
    return dp[i][mask] = ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    rep(i, n) {
        rep(j, n) {
            cin >> c[i][j];
        }
    }
    cout << solve(0, (1 << n )- 1, n);

}

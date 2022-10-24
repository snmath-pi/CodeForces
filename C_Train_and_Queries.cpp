#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define all(x) (x).begin() , (x).end()
#define sz(x) (x).size() 
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ROF(i,b,a) for(int i=a-1;i>=b;--i)
#define vi vector<int> 
#define vl vector<long long>

/**********************************************************/
int MOD = 1e9 + 7 ;
long long binpow(long long a, long long b) {a %= MOD;long long res = 1;while (b > 0) {if (b & 1){res = res * a % MOD;}a = a * a % MOD;b >>= 1;}return res;}

/*********************************************************/
/* check for long long !! */
void solve() {
    int n , m ;
    cin >> n >> m ;
    map<int,pair<int,int>> mp ;
    FOR(i,0,n){
        int x ;
        cin >> x; 
        if(mp.count(x) == 0){
            mp[x].first = i ;
            mp[x].second = i ;
        }else mp[x].second = i ;
    }
    while(m--){
        int a , b ;
        cin >> a >> b ;
        if(mp.count(a) == 0 || mp.count(b) == 0 || mp[a].first > mp[b].second){
            cout << "NO\n";
        }else cout << "YES\n" ;
    }

    



}

int main() {
    std::ios_base::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    int t ;
    std::cin >> t;
    while(t--) {
        solve() ;
    }
}


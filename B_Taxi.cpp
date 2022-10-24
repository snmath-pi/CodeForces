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
    int n ;
    cin >>n ;
    // int a[n] ;
    // FOR(i,0,n) cin >> a[i] ;
    // sort(a ,a +n) ;
    // set<int>  s = {1 ,2 ,3,4} ;
    // int dp[n] ;
    // dp[0] = 0 ;
    // for(auto x:a){
    //     dp[x] = min(dp[x] , s.find(dp[x])) ;
    //     dp[x] += dp[x] ;
    // }
    // cout << dp[0] << "\n" ;

    // int dp[n] ;
    // dp[0] = 0 ;
    // for(auto x : a){
    //     dp[x] = min(dp[x] , x - dp[x]) ;
    // }
    // cout << dp[0] << "\n" ;
    map<int,int> mp ;
    FOR(i,0,n){
        int x ;
        cin >> x ;
        mp[x]++ ;
    }
    for(auto x:mp){

    }
    
    int cnt = mp[4] ;
    mp[4] = 0 ;
    cnt += mp[3] ;
    mp[1] = max(0 , mp[1] - mp[3] ) ;
    cnt += mp[2] >> 1 ;
    mp[1] += ((mp[2] & 1) <<1) ;
    cnt += (mp[1] + 3)>>2 ;
    // cnt += ((three>0 && one >0)?(three-one):0) ;
    // cnt += (abs(three-one)) ;
    // cnt += (two ; 
    cout << cnt << "\n" ;







}

int main() {
    std::ios_base::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    solve() ;
}


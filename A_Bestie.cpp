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
    cin >> n ;
    vi a(n+1) ;
    FOR(i,1,n+1) cin >> a[i] ;
    // cout << a[n] << "\n" ;
    if(n == 1){
    	cout << ((a[1] ==1)?0:1) << "\n";
    	return ; 
    }
    int res=  a[1] ;
    int ans  = -1e6 ;
    FOR(i,2,n+1){
        res = __gcd(a[i] , res) ;
        if(res == 1){
            ans = 1 ;
            break ;
        }else{
            ans = res ;

        }
    }
    // cout << a[n] << "\n"  ;
    if(ans == 1){
        cout << 0 << "\n";
        return ;
        
    }
    if(__gcd(ans , n) == 1){
        cout << 1 << "\n" ;
        return ;
    }
    if(__gcd(ans , n-1 ) ==1){
        cout << 2 << "\n" ;
        return ;
    }cout << 3 << "\n" ;





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


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
int n , m ;
vector<int> a ;
bool good(double x){
    FOR(i,1,n-1){
        if(abs(a[i] - x) > a[i-1] || a[i] + x < a[i+1]) return false ;
    }
    return true ;
}
void solve() {
    cout << setprecision(10) ;
    
    cin >> n >> m ;
    // int a[n] ;
    a.resize(n) ;
    FOR(i,0,n) cin >> a[i] ;
    sort(all(a)) ;
    double l = 0 , r = m ;
    double ans = 1e9 ;   
    while(r > l +1){
        double mid = (l + r ) /2 ;
        if(good(mid)){

            r = mid   ;
            // ans = min(ans , mid) ;
        }else{
            l  = mid ;
            l = min( l , mid) ;
        }
    }
    cout << l << "\n" ;
   
    


}

int main() {
    std::ios_base::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    solve() ;
}


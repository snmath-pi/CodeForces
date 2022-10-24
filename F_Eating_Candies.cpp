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
    vl a(n) ;
    FOR(i,0,n) cin >> a[i] ;
    int64_t l = 0 , r = n-1 ;
    // vl b ;
    int64_t A = a[0]  , B = a[n-1] , cnt(0) ;
    while(l <r){
        if(A == B) cnt = max(cnt , l + 1 + n - r ) ;
        if(A <= B){
            l++ ;
            A += a[l] ;
            
        }else if(B < A) {
            r-- ;
            B += a[r] ;
            
        }


    }
    // cout << *max_element(all(b)) << "\n" ;
    cout << cnt << "\n" ;
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


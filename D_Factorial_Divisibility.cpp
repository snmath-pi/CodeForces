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
    int n , x ;
    cin >> n >> x ;
    vi a(n) ;
    FOR(i,0,n){
        cin >> a[i] ;
    } 
    ll sum = accumulate(all(a) , 0) ;
    cout << ((sum%x)?"No":"Yes") << "\n" ;



}

int main() {
    std::ios_base::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;
    std::cout.tie(nullptr) ;
    solve() ;
}


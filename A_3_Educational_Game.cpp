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
    vi a(n) ;
    FOR(i,0,n) cin >> a[i] ;
    int l = 0 , r = n-1 ;
    vi b ;
    int64_t A(0) , B(0) ;
    while(l <=r){
        if(l != r){
            A += a[l] ;
            B += a[r] ;
            cnt ++ ;
            if(A == B) b.push_back(cnt) ;
            l++ , r-- ;
        }else{
            if(A == B) break ;
            else{
                if(A < B) A+= a[l] ;
                if( A >B) B+= a[r] ;
                cnt++ ;
                b.push_back(cnt) ;
            }
        }


    }
    cout << *max_element(all(b)) << "\n" ;



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


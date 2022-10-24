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
    string s ;
    cin >> n >> s ;
    int64_t cnt(n) ;
    stack<char> st ;
    vector<int> a ;
    FOR(i,1,n){
        if(s[i] != s[i-1]) cnt+= i ;
    }
    // FOR(i,0,sz(a)-1){
    //     if(a[i] == 1 && a[i+1] == 0 || a[i] == 0 && a[i+1] == 1){
    //         cnt++ ;
    //     }
    // }
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


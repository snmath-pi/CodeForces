// O(N) doesn't giving TLE's 
#include<bits/stdc++.h>
using namespace std ;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1) ;
    for(int i=1; i<=n; i++) {
        cin >> a[i] ;
    }
    int M[n+1] = {0} ;
    
    int val = 0 ;
    int cur = 0 ;
    int res = 0 ;
    for(int i=1; i<=n; i++) {
        val ^= a[i] ;

        if(val == k) res++ ;

        if(val ^ k < 2*n) {
            res += M[val ^ k] ;
        }
        M[val]++ ;

    }

    cout << res << "\n" ;

}

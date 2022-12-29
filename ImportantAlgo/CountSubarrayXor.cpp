// O(nlogn) 
#include<bits/stdc++.h>
using namespace std ;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1) ;
    for(int i=1; i<=n; i++) {
        cin >> a[i] ;
    }
    unordered_map<int, int> M ;
    
    int val = 0 ;
   
    int res = 0 ;
    for(int i=1; i<=n; i++) {
        val ^= a[i] ;

        if(val == k) res++ ;

        if(M.find(val ^ k) != M.end()) {
            res += M[val^k] ;
        }
        M[val]++ ;

    }

    cout << res << "\n" ;

}

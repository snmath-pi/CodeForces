#include<bits/stdc++.h>
using namespace std ;
int nCr(int n, int r, int p){
    r = (r > n - r)?n-r:r ;
    int C[r + 1] ={0} ;
    C[0] = 1 ;
    for(int i=1; i<=n; i++ ){
        for(int j=min(i, r); j> 0; j--){
            C[j] = (C[j-1] + C[j]) % p ;
        }
    }
    return C[r] ;
}
int main(){
    int n, r, p ;
    cin >> n >> r >> p ;
    cout << nCr(n, r, p) ;
}

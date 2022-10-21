#include<bits/stdc++.h>
#define ll long long 
using namespace std ;
struct SegTree{
    vector<ll > values ;
    ll size ;
    void init(ll n){
        size = n ;
        // while(size <n) size *= 2 ;
        values.resize(4*n); 
 
 
    }
    
    void Build(vector<ll>&a , ll x , ll lx , ll rx){
        if(rx - lx == 0){
            values[x] = a[lx] ;
            return ;
        }
        ll m = (lx + rx) / 2 ;
        Build(a , 2*x  , lx , m) ;
        Build(a , 2*x +1 , m+1 , rx) ;
        values[x] = min(values[2*x ] , values[2*x+1]) ;
    }
    
    
    ll calc(ll l , ll r , ll x , ll lx , ll rx){
        if(lx > r || l>rx) return INT_MAX ;
        if(lx >= l && rx <= r) return values[x] ;
        ll m = (lx + rx)  / 2 ;
        ll s1= calc(l , r , 2*x , lx , m) ;
        ll s2 = calc(l , r , 2*x+1 , m+1 , rx) ;
        return min(s1,s2 ) ;
    }
    
};
int main() {
    ios_base::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    cout.tie(nullptr) ;
    ll n , m ;
    cin >> n >> m ;
    vector<ll> a(n) ;
    for(int i=0; i<n; i++) cin >> a[i] ;
    SegTree st ;
    st.init(n) ;
    st.Build(a,1,0,n-1) ;
    while(m--){
        ll l ,r  ;
        cin >> l >> r ;
        l-- ; r-- ;
        cout << st.calc(l,r,1,0,n-1) << "\n" ;
    }
 
    
    
}

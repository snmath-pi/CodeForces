#include<bits/stdc++.h>
using namespace std ;
struct SegTree{
	int size ;
	vector<long long> sums ;
	
	void init(int n){
		size = 1 ;
		while(size < n) size*=2 ;
		sums.assign(2*size , 0LL) ;




	}
	void BuildTree(vector<int>&a , int x ,int lx , int rx){
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				sums[x] = a[lx] ;
			}
			return ;

		}
		int m = (lx + rx)/ 2 ;
		BuildTree(a , 2*x +1 , lx , m) ;
		BuildTree(a , 2*x+2 , m , rx) ;
		sums[x] = sums[2*x+1] + sums[2*x+2] ;
	}
	void BuildTree(vector<int> &a){
		BuildTree(a,0,0,size) ;
	}

	void set(int i , int v ,int x , int lx , int rx){
		if(rx - lx ==1){
			sums[x] = v ;
			return ;

		}
		int m = (lx + rx) / 2 ;
		if(i <m){
			set(i,v,2*x+1 ,lx , m) ; 
		}else{
			set(i , v , 2*x +2 , m , rx) ;
		}
		sums[x] = sums[2*x+1] + sums[2*x+2] ;
	}
	void set(int i , int v){
		set(i , v,0 ,0 , size) ;
	}
	long long sum(int l , int r , int x , int lx , int rx){
		if(lx >= r|| lx>= rx) return 0 ;
		if(lx >= l && rx <= r) return sums[x] ;
		int m = (lx + rx) / 2 ;
		long long s1 = sum(l , r ,2*x+1 , lx , m) ;
		long long s2 = sum(l ,r , 2*x+2, m , rx) ;
		return s1 + s2 ;
	}
	long long sum(int l , int r){
		return sum(l , r ,0 ,0 , size) ;
	}

};
int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	SegTree st ;
	st.init(n) ;
	vector<int> a(n) ;
	for(int i=0; i<n; i++){
		cin >> a[i] ;
	}
	st.BuildTree(a) ;
	while(m--){
		int op ;
		cin >> op ;
		if(op == 1){
			int i , v ;
			cin >> i >> v ;
			st.set(i , v) ;
		}else{
			int l , r ;
			cin >> l >> r ;
			cout << st.sum(l,r) << "\n"  ;

		}
	}
	return 0 ;

}

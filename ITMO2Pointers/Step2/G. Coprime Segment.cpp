#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long

const int N = 1e5 + 10;
ll A[N];
int cnt = 0;
ll n, k;
const ll inf  = 2e18;
struct stack {
	vector<ll> s, sg{0};
	void push(ll x) {
		s.push_back(x);
		sg.push_back(__gcd(sg.back(), x));
		return;
	}
	ll pop() {
		ll res = s.back();
		s.pop_back();
		sg.pop_back();
		return res;
	}
	bool empty() {
		return s.empty();
	}
	ll back() {
		return s.back(); 
	}
} s1, s2;
void add(ll x) {
	s2.push(x);
}

void remove() {
	if(s1.empty()) {
		while(!s2.empty()) {
			s1.push(s2.pop());
		}
	}
	s1.pop();
}

bool good() {
	return __gcd(s1.sg.back(), s2.sg.back()) == 1;
}
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> A[i];
	}
	int res = 1e9;
	
	for(int l = 0, r=0; r<n; r++) {
		s2.push(A[r]);
		while(good()) {
			res = min(res, r-l+1);
			remove();l++;
		}		
	}

	cout << (res==1e9?-1:res)  << "\n";


}

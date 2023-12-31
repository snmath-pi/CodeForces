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
	vector<ll> s, smx = {LLONG_MIN}, smn={LLONG_MAX};
	void push(ll x) {
		s.push_back(x);
		smx.push_back(max(smx.back(), x));
		smn.push_back(min(smn.back(), x));
		return;
	}
	ll pop() {
		ll res = s.back();
		s.pop_back();
		smx.pop_back();
		smn.pop_back();	
		return res;
	}
	bool empty() {
		return s.empty();
	}
	ll mx() {
		return smx.back();
	}
	ll mn() {
		return smn.back();
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
	ll mx = max(s1.mx(), s2.mx());
	ll mn = min(s1.mn(), s2.mn());
	return mx - mn <= k;
}
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		cin >> A[i];
	}
	ll res = 0;

	for(int l = 0, r=0; r<n; r++) {
		s2.push(A[r]);
		while(!good()) {
			remove(); ++l;
		}
		res += (r-l+1);
	}

	cout << res  << "\n";


}

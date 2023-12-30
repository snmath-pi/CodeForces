#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long

const int N = 1e5 + 10;
const int LG = 8;
ll A[N];
int cnt = 0;
ll freq[N];
void add(int x) {
	++freq[x];
	if(freq[x] == 1) cnt++;
}
int remove(int x) {
	--freq[x];
	if(!freq[x]) cnt--;
	return cnt;
}
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		cin >> A[i];
	}
	ll res = 0;
	for(int r = 0, l = 0; r < n; r++) {
		add(A[r]);
		while(cnt > k) {
			remove(A[l++]);
		}
		res += (r - l + 1);
	}
	cout << res << '\n';
}

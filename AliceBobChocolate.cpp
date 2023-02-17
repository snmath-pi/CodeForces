/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
//https://codeforces.com/problemset/problem/6/C
// Accepted
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   	int N;
   	cin >> N;
   	vector<int> a(N);
   	for(int i=0; i<N; i++) {
   		cin >> a[i];
   	}
   	int L =0,R = N-1;
   	i64 Tot_Alice = 0, Tot_Bob = 0;
   	int Bob=0, Alice = 0;
   	while(R >= L) {
   		if(Tot_Alice == 0) {
   			Tot_Alice += a[L];
   		}
   		if(Tot_Bob == 0) {
   			Tot_Bob += a[R];
   		}
   		if(Tot_Bob < Tot_Alice ) {
   			Bob++;
   			if(R-1 >= L) Tot_Bob += a[R-1];
   			R--;
   		}
   		else  {
   			Alice++;

   			if(L+1 <= R) {
   				Tot_Alice += a[L+1];
   			}
   			L++;
   		}
   		
   	}
   	cout << Alice << " " << Bob;
    
    return 0;
}
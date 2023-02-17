/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
//https://codeforces.com/problemset/problem/9/C
// Accepted

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   	int N;
   	cin >> N;
   	vector<int> digits;
   	int W = N;
   	while(W) {
   		digits.push_back(W % 10);
   		W /= 10;
   	}
   	vector<int> temp_digits((int)digits.size(), 0);
   	// for(auto x:digits) cout << x << " ";
   	// cout << "\n";
   	reverse(digits.begin(), digits.end());
   	
   	for(int i=0; i<(int) digits.size(); i++) {
   		if(digits[i] > 1) {
   			for(int j = i; j<(int) digits.size(); j++) {
   				temp_digits[j] = 1;
   			}
   			break;
   		}
   		else temp_digits[i] = digits[i];
   	}
    i64 ans = 0;
    // for(auto x:temp_digits) cout << x << " ";
    for(int i=(int) temp_digits.size()-1; i>=0; i--) {
    	ans += (temp_digits[i]) * (1 << ((int)temp_digits.size()-i -1 ));
    }
    cout << ans << "\n";
    return 0;
}
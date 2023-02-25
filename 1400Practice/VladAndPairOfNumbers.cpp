#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        // a ^ b = N
        int a = N;
        int b = 0;
        
        for(int i=30; i>=0; i--) {
            if(a & (1LL<<i)) continue;
            else {
                if(2 * N >= a + b + (2LL << i)) { // next higher power (2 * 1LL << i);
                    a += (1LL << i);
                    b += (1LL << i);
                }
            }
        }
        if(a + b != 2 * N) {
            cout << -1 << "\n";
        } else {
            cout << a  << " " << b << "\n";
        }
    }
}

#include<bits/stdc++.h>
using namespace std;

int a[100005];
int RMQ[100005][19];
const int LOG = 19;

int query(int L, int R) {
    int length = R - L + 1;
    int k = 0;
    while((1 << (k+1)) <= length) k++;

    return min(RMQ[L][k], RMQ[R-(1<<k)+1][k]);
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        RMQ[i][0] = a[i];
    }
    for(int j=1; j<LOG; j++) {
        for(int i=0; i + (1 << j) - 1<n; i++) {
            RMQ[i][j] = min(RMQ[i][j-1], RMQ[i + (1 << j-1)][j-1]);
        }
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << '\n';
    }
}

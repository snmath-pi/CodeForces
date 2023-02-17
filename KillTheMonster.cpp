/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
// https://codeforces.com/contest/1633/problem/C
// Accepted ~~Saksham Negi
#include <bits/stdc++.h>
using namespace std ;
using i64 = long long;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "->"; god(x); cerr << "\n";
#else 
#define debug(x)
#endif 
void god(i64 UWU) { cerr << UWU;}
void god(int UWU) { cerr << UWU;}
void god(string UWU) { cerr << UWU;}
void god(char UWU) { cerr << UWU;}
void god(double UWU) {cerr << UWU;}
void god(long double UWU) {cerr << UWU;}
template<class T> void god(vector<T> V) {cerr << "["; for(T I:V) {god(I); cerr << " ";} cerr << "]";}

i64 hc, dc, hm, dm, k, w, a, T;
bool dp[300000];
void solve() {
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    i64 hit_c = (hm + dc - 1) / dc;
    i64 hit_m = (hc + dm - 1) / dm;
    debug(hit_c); debug(hit_m); debug(k);
    if(hit_c <= hit_m) {
        cout << "YES\n";
    } else {
        if(!k) {
            cout << "NO\n";
        } else {
            auto Y = [&](i64 A, i64 B) {
                return ((A + B - 1) / B);
            };
            
            for(int i=0; i<=k; i++) {
                i64 temp_hc = hc, temp_dc = dc;
                temp_dc += (w * i);
                temp_hc += (a * (k - i));
                debug(i);
                i64 hit_c_temp = Y(hm, temp_dc);
                i64 hit_m_temp = Y(temp_hc, dm);
                debug(hit_m_temp); debug(hit_c_temp); debug(dc);
                if(hit_c_temp <= hit_m_temp) {
                    cout << "YES\n";
                    return;
                }
                
            }
            cout << "NO\n";

        }
    }
}
int main() {

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}

/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
//https://codeforces.com/problemset/problem/15/A
// Accepted
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
int N, T, center, side;
void solve() {
    cin >> N >> T;
    vector<pair<double, double>> houses(N);
    for(int i=0; i<N; i++) {
        cin >> houses[i].first >> houses[i].second;
    }
    int possible_positions = 2;
    sort(houses.begin(), houses.end());
    for(int i=0; i<N-1; i++) {
       
        double length = abs((houses[i].first + houses[i].second / 2) - (houses[i+1].first - (houses[i+1].second / 2)));
        
        if(length == T) possible_positions += 1;
        else if(length > T) possible_positions += 2;
        else if(!length) continue;

    }
    debug(possible_positions);
    cout << possible_positions;
}
int main() {

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}

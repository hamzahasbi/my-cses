/*
 Author: Hamza Hasbi
 @Copyrights: __Morty
*/
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
 #pragma GCC optimize("O3")
#endif
#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define ud unsigned double
#define uf unsigned float
#define pi 2 * acos(0.0)
#define module cin.ignore()
//inline long long lcm(ll a,ll b) {return a * b / __gcd(a,b);}
//inline long long gcd(ll a,ll b) {return 1LL * b == 0 ? a : gcd(1LL*b, a * 1LL % b * 1LL);}
inline bool IsPowerOfTwo (ull x){ return (x != 0) && ((x & (x - 1)) == 0);}
using namespace std;
void READ() {
 #ifndef ONLINE_JUDGE
   freopen("IO/Input.in", "r", stdin);
  #endif
}

unordered_map<long long, vector<long long>>dp;
vector<long long> solve(long long a, vector<long long>p) {
    if (dp.count(a)) return dp[a];
    vector<long long>curr = p;
    curr.push_back(a);
    if (a == 1) return dp[a] = curr;
    if (a & 1) {
        return dp[a] = solve(a * 3 + 1, curr);
    }
    else {
        return dp[a] = solve(a / 2, curr);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int n;
    cin >> n;
    vector<long long> res, begin;
    res = solve(n * 1LL, begin);

    for(auto &el : res) cout << el << " ";
    return 0;
}
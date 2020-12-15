/*
 Author: Hamza Hasbi
 @Copyrights: __Morty
*/
#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
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
const long long MOD = (ll) 1e9 + 7;
long long powMod(long long a, long long to) {
    if (to == 1) return a;
    if (to == 0) return 1;
    if (to & 1) {
        long long sub = to / 2;
        long long ans = powMod(a, sub);
        ans = ((ans % MOD) * (ans % MOD)) % MOD;
        ans *= a % MOD;
        return ans % MOD;
    } else {
        long long sub = to / 2;
        long long ans = powMod(a, sub) % MOD;
        ans = ((ans % MOD) * (ans % MOD)) % MOD;
        return ans;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int n;
    cin >> n;
    cout << powMod(2 * 1LL, n * 1LL) << endl;
    return 0;
}
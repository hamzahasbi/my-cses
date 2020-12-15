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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int n;
    cin >> n;
    if (n == 2 || n == 3) puts("NO SOLUTION");
    else {
        for(int i = 2; i <= n; i += 2) cout << i << " ";
        for(int i = 1; i <= n; i += 2) cout << i << " ";
    }
    cout << endl;
    return 0;
}
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
    long long sum = (long long) n * (n + 1) / 2;
    // cout << sum << endl;
    if (sum & 1) {
        puts("NO");
    }
    else {
        cout << "YES" << endl;
        sum /= 2;
        int i = n;
        vector<int>l;
        vector<bool>marked(n + 1);
        while(sum > 0) {
            if (sum - i >= 0) {
                sum -= i;
                l.push_back(i);
                marked[i] = true;
            }
            i -= 1;
        }
        cout << l.size() << endl;
        for(auto &el : l) cout << el << " ";
        cout << endl;
        cout << n - l.size() << endl;
        for(int j = 1; j <= n; ++j) {
            if (!marked[j]) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
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
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    
    int n;
    cin >> n;
    long long x;
    cin >> x;
    vector<pair<long long, int>> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = (i + 1);
    }
    sort(a.begin(), a.end());

    for(int i = 0; i < n; ++i) {
        auto el = a[i].first;
        int l = i + 1, r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            // cout << el << " " << a[mid].first << endl;
            if (a[mid].first == x - el) {
                cout << a[i].second << " " << a[mid].second << endl;
                return 0;
            } 
            else if (a[mid].first > x - el) {
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
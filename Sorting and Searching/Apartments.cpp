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
    // auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    
    int n,m;
    long long k;

    cin >> n >> m >> k;
    vector<long long>a(n), b(m);
    // unordered_map<long long, int>disp;
    multiset<long long> app;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> b[i];
        app.insert(b[i]);
        // disp[b[i]]++;
    }

    // sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    long long ans = 0;

    for(int i = 0; i < n; ++i) {
        long long l = a[i] - k;
        long long r = a[i] + k;

        // auto possible = lower_bound(b.begin(), b.end(), l);
        auto possible = app.lower_bound(l);
        if (possible != app.end()) {
            // auto found = possible - b.begin();
            // cout << a[i] << " " << l << " " << *possible << " " << r<< endl;
            if (*possible <= r ) {
                ans++;
                app.erase(possible);
            }
        }
    }
    cout << ans << endl;
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
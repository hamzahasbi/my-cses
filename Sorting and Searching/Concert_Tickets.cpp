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
    
    int n, m;
    cin >> n >> m;
    vector<long long>h(n), t(m);
    multiset<long long> s;
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
        s.insert(h[i]);
    } 
    for(int i = 0; i < m; ++i) {
        cin >> t[i];

        auto a = s.lower_bound(t[i]);

        if (a == s.end()) {
            if (a == s.begin()) {
                cout << -1 << endl;
            }
            else {
                auto before = prev(a);
                cout << *before << endl;
                s.erase(before);
            }
        } else {
            if (*a == t[i]) {
                cout << *a << endl;
                s.erase(a);
            } else{
                if (a == s.begin()) {
                    cout << -1 << endl;
                } else {
                    auto before = prev(a);
                    cout << *before << endl;
                    s.erase(before);
                }
               
            }
        }


    }
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
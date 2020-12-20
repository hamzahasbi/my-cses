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
    
    int n;
    cin >> n;
    vector<pair<long long, long long>>p(n);
    map<long long, int>mp;
    for(int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
        mp[p[i].first]++;
        mp[p[i].second]--;

    }

    // sort(p.begin(), p.end(), [] (pair<long long, long long>A, pair<long long, long long>B) {
    //     if (A.second < B.second) return true;
    //     if (A.second == B.second && A.first < B.first) return true;
    //     return false ;
    // });

    int ans = 0;
    int curr = 0;

    for(auto &el : mp) {
        curr += el.second;
        ans = max(ans, curr);
    }


    cout << ans << endl;
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
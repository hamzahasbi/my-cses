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
vector<long long> ans;

void subsetSums(vector<long long> arr, int l, int r,  long long sum = 0) 
{ 
    if (l > r) 
    { 
        ans.push_back(sum); 
        return; 
    } 
  
    // Subset including arr[l] 
    subsetSums(arr, l + 1, r, sum + arr[l]); 
  
    // Subset excluding arr[l] 
    subsetSums(arr, l + 1, r, sum); 
} 
int main() {
    // auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int n;
    cin >> n;
    vector<long long>p(n);
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> p[i];
        sum += p[i];
    }
    subsetSums(p, 0, n - 1, 0);    
    long long res = LLONG_MAX;
    for(auto &el : ans) {
        // if (!ans.count((sum - el))) continue;
        long long cmp = abs((sum - el) - el);
        res = min(res, cmp);
    }
    cout << res << endl;
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
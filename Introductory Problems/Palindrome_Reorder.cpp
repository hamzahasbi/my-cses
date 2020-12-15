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
//    freopen("IO/output.out", "w", stdout);
  #endif
}
int freq[27];

int main() {
    // auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // READ();
    string s;
    cin >> s;
    memset(freq, 0, sizeof freq);
    int c = 0;
    for(int i = 0; i < s.size(); ++i) {
        freq[s[i] - 'A']++;
    }

    for(int i = 0; i <= 25; ++i) {
        c += freq[i] & 1;
    }

    if (c > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    string l,r; 
    l = r = "";
    char q;
    for(int i = 0; i <= 25; ++i) {
        // printf("%c\n", i + 'A');
        if (!freq[i]) continue;
        string a;
        int curr = freq[i] / 2;
        if (freq[i] & 1) {
            q = (char) i + 'A';
        }
        a.assign(curr, (char) i + 'A');
        l += a;
        r += a;
    }

    // cout << l << " " << r << endl;
    int mn = min(l.size(), r.size());
    bool side = 1;
    for(int i = 0; i < mn; ++i) {
        side &= l[i] == r[i];
    }
    reverse(r.begin(), r.end());
    // cout << l << " " <<  r << endl;
    if (side) {
        if (c == 1) l += q; 
        string ans = l + r;
        cout << ans << endl;
    }
    else cout << "NO SOLUTION" << endl;


    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
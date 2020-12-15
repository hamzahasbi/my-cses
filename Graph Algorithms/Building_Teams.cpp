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
const int MAXN = (int)1e5 + 1;
int n, m;
vector<int>graph[MAXN];
int vis[MAXN];
bool IMP = false;

void dfs(int node, int color = 1) {
    vis[node] = color;
    for(auto &v : graph[node]) {
        if (vis[v] == -1) {
            dfs(v, color == 1 ? 2 : 1);
        } else if (vis[v] == color) {
            IMP = true;
            return;
        }
    }
}
int main() {
    // auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    

    cin >> n >> m;
    memset(vis, -1, sizeof vis);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i = 1; i <= n; ++i) {
        if (vis[i] == -1) {
            dfs(i);
        }
    }

    if (IMP) cout << "IMPOSSIBLE" << endl;
    else {
        for(int i = 1; i <= n; ++i) {
            printf("%d%c", vis[i], i == n ? '\n' : ' ');
        }
    }
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
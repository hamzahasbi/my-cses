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
int n, m;
char grid[1001][1001];
pair<int, char> vis[1001][1001];
pair<int, int>b, e;

void bfs() {

  queue<pair<int, int>>q;
  q.push(b);
  vis[b.first][b.second] = {0, '*'};

  while(!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();

    // cout << i << " " << j << endl;
    if (i + 1 < n && grid[i + 1][j] != '#') {
      if (vis[i + 1][j].first == INT_MAX) {
        vis[i + 1][j] = {1 + vis[i][j].first, 'D'};
        q.push({i + 1, j});
      }
      
    }
    if (i - 1 >= 0 && grid[i - 1][j] != '#') {

      if (vis[i - 1][j].first == INT_MAX) {
        vis[i - 1][j] = {1 + vis[i][j].first, 'U'};
        q.push({i - 1, j});
      }
      
    }
    if (j + 1 < m && grid[i][j + 1] != '#') {
      if (vis[i][j + 1].first == INT_MAX) {
        vis[i][j + 1] = {1 + vis[i][j].first, 'R'};
        q.push({i, j + 1});
      }
      
    }
    if (j - 1 >= 0 && grid[i][j - 1] != '#') {
      if (vis[i][j - 1].first == INT_MAX) {
        vis[i][j - 1] = {1 + vis[i][j].first, 'L'};
        q.push({i, j - 1});
      }
      
    }
  }
}
int main() {
    // auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // READ();

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%s", grid[i]);
      for(int j = 0; j < m; ++j) {
        if (grid[i][j] == 'A') b = {i, j};
        if (grid[i][j] == 'B') e = {i, j};
      }
    }
    
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; ++j) {
        vis[i][j] = {INT_MAX, '*'};
      }
    }

    bfs();

    // for(int i = 0; i < n; ++i) {
    //   for(int j = 0; j < m; ++j) {
    //     cout << vis[i][j].first << " ";
    //   }
    //   cout << endl;
    // }

    if (vis[e.first][e.second].first == INT_MAX) printf("NO\n");
    else {
      printf("YES\n");
      printf("%d\n", vis[e.first][e.second].first);
      auto res = vis[e.first][e.second];
      auto fin = e;
      string path = "";
      while(true) {
        if (fin == b) break;
        path += res.second;
        // cout << fin.first << " " << fin.second << endl;
        if (res.second == 'U') {
          fin.first += 1;
        } else if (res.second == 'D') {
          fin.first -= 1;
        } else if (res.second == 'L') {
          fin.second += 1;
        } else {
          fin.second -= 1;
        }
        res = vis[fin.first][fin.second];
      }
      reverse(path.begin(), path.end());
      printf("%s", path.c_str());
    }

    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}




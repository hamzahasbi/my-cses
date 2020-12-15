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

int ans = 0;
bool takencols[8], takendiag1[16], takendiag2[16];

void place(string board[8], int r, int &ans)
{
    if (r == 8)
    {
        ans++;
        return;
    }
    for (int c = 0; c < 8; c++)
    {
        if (board[r][c] == '.')
        {
            if (!takencols[c] && !takendiag1[r - c + 8 - 1] && !takendiag2[r + c])
            {
                takencols[c] = takendiag1[r - c + 8 - 1] = takendiag2[r + c] = true;
                place(board, r + 1, ans);
                takencols[c] = takendiag1[r - c + 8 - 1] = takendiag2[r + c] = false;
            }
        }
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    string board[8];
    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }
    place(board, 0, ans);
    cout << ans << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
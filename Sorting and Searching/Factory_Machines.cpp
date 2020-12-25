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

vector<ll> v;
int n;
ll t;
 
ll sum(ll x) {
	ll res = 0LL;
	for(ll item : v) {
		res += x / item;
		if (res > t) break;
	}
	return res;
}
 
int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin >> n;
	cin >> t;
	
	v.resize(n);
	
	for(ll &item : v) cin>>item;
	
	ll mx = 1e18;
	ll mn = 0;
	
	while (mn <= mx) {
		ll mid = mn + (mx - mn) / 2;
		ll s = sum(mid);
		
		if(s >= t) {
			mx = mid - 1;
		} else {
			mn = mid + 1;
		}
	}

	 cout << mn << endl;
	
	return 0;
}
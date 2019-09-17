#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> matr;
	
matr mult(matr A, matr B) {
	matr C(A.size());
	for (int i = 0; i < A.size(); ++i)
		for (int j = 0; j < B[0].size(); ++j) {
			ll v = 0;
			for (int k = 0; k < A[0].size(); ++k) {
				v = (v+A[i][k]*B[k][j]+mod) % mod;
			}
			C[i].push_back(v);
		}
	return C;
}
	
matr expo(matr A, matr B, int n) {
	if (n == 1) return mult(A, B);
	if (n & 1) return mult(expo(A, B, n-1), B);
	return expo(A, mult(B, B), n >> 1);
}
	
int main(){
	ll x,y,n;
	cin >> x >> y >> n;
	matr m = {{1,1}, {-1,0}};
	vi b = {(y+mod)%mod,(x+mod)%mod};
	// cout << n << ' ' <<  (n < 2) << '\n';
	if (n < 3) cout << (b[2-n]+mod)%mod << '\n';
	else cout << expo({b}, m, n-2)[0][0] << '\n';
}

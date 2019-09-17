#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> matr;

ll mod;

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

ll expo(ll A, ll B) {
	if (B == 0) return 1;
	if (B & 1) return expo(A, B-1) * A;
	return expo(A*A, B >> 1);
}

matr expo(matr A, matr B, ll n) {
	if (n == 1) return mult(A, B);
	if (n & 1) return mult(expo(A, B, n-1), B);
	return expo(A, mult(B, B), n >> 1);
}
	
int main(){
	ll x,y,n;
	matr m = {{1,1}, {1,0}};
	scanf("%lld %lld", &x, &y); 
	// printf("x=%d x=%d\n", x, y)	;
	vi b = {{x%y, x}};
	mod = y;
	ll ans;
	if (x < 2)
		ans = x % mod << '\n';
	else
		ans = expo({b}, m, x-1)[0][0] << '\n';
	if (!ans)
		cout << "No\n";
	else
		cout << "Yes\n";
}

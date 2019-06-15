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
				v = (v+A[i][k]*B[k][j]) % mod;
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
	
ll get(int id){
	if (id == 1) return 0;
	if (id == 2) return 1;
	if (id < 3) return id;
	matr m = {{1,0,0}, {1,1,1}, {1,1,0}};
	vi b = {1,1,0};
	return expo({b}, m, id-2)[0][0];
}
	
int main(){
	int t;
	cin >> t;
	while (t--) {
		ll x,y, fx, fy;
		cin >> x >> y;
		
		fy = get(y+1);
		fx = get(x);
		// printf("fx=%d fy=%d\n", fx, fy);
		cout << (fy-fx+mod) % mod << '\n';
		// cout <<"sz" << m.size() << '\n';
	}
} 
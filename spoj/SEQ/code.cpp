#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000
typedef vector<long long> vi;
typedef vector<vi> matr;

matr mult(matr A, matr B) {
	matr C(A.size());
	for (int i = 0; i < A.size(); ++i)
		for (int j = 0; j < B[0].size(); ++j) {
			long long v = 0;
			for (int k = 0; k < A[0].size(); ++k) {
				v = (v+A[i][k]*B[k][j]) % MOD;
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
	int t;
	cin >> t;
	while (t--) {
		int x,k,n;
		cin >> k;
		vi b, c;
		for (int i = 0; i < k; ++i) {
			cin >> x;
			b.push_back(x);
		}
		for (int i = 0; i < k; ++i) {
			cin >> x;
			c.push_back(x);
		}
		cin >> n;
		if (n <= k) {
			cout << b[n-1] << '\n';
			continue;
		}
		matr m(k);
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < k; ++j)
				if (j+1==k) m[i].push_back(c[k-i-1]);
				else if (i-1==j) m[i].push_back(1);
				else m[i].push_back(0);
		// for (int i = 0; i < k; ++i){
		// 	for (int j = 0; j < k; ++j)
		// 		cout << m[i][j] << ' ';
		// 	cout << '\n';
		// }

		matr zet = expo({b}, m, n-1);
		cout << zet[0][0] << '\n';
		// cout <<"sz" << m.size() << '\n';
	}
}
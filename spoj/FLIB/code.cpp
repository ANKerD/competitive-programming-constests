#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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
		cin >> x;
	}
}
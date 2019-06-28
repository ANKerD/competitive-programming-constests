// #include <bits/stdc++.h>
// using namespace std;
// #define mod 1000000007LL
// typedef long long ll;
// typedef vector<ll> vi;
	
	
// inline void mult(ll A[][3], ll B[][3], ll C[][3], int mi = 3) {
// 	for (register int i = 0; i < mi; ++i) 
// 		for (int j = 0; j < 3; ++j)
// 			for (register int k = 0; k < 3; ++k) 
// 				C[i][k] = C[i][k]+A[i][k]*B[k][j];
// }
	
// inline void expo(ll A[3][3], ll k) {
// 	int n = 3;
// 	ll resp[3][3] = {{1,0,0}, {0,1,0}, {0,0,1}};
// 	ll aux[3][3] = {{1,0,0}, {0,1,0}, {0,0,1}};
// 	ll B[3][3];

//  	for (int i = 0; i < 3; ++i) 
// 		for (int j = 0; j < 3; ++j)
// 			B[i][j] = A[i][j];

//   	while(k) {
// 		if(k & 1) {
// 			mult(resp, B, aux);
// 			swap(resp, aux);
// 		}
// 		mult(B, B, aux); 
// 		swap(B, aux);
// 		k >>= 1;
// 		for(register int i = 0; i < n; i++) 
// 			for(register int j = 0; j < n; j++)
// 				if (B[i][j] >= mod)
// 					B[i][j] = B[i][j] % mod;
// 	}

//   	for (int i = 0; i < 3; ++i) 
// 		for (int j = 0; j < 3; ++j)
// 			A[i][j] = B[i][j];
// }
	
// int main(){
// 	ll x;
// 	int t;
// 	scanf("%d", &t);
// 	for (int i = 0; i < t; ++i) {
// 		ll m[3][3] = {{1,0,0}, {8,5,3}, {5,3,2}};
// 		ll b[3][3] = {{2,1,1}, {0,0,0}, {0,0,0}};
// 		scanf("%lld", &x);
// 		if (x == 0)
// 			printf("0\n");
// 		else if (x == 1) 
// 			printf("2\n");
// 		else {
// 			expo(m, x-1);
// 			ll aux[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
// 			mult(b, m, aux);
// 			for (int i = 0; i < 3; ++i) {
// 				for (int j = 0; j < 3; ++j)
// 					cout << m[i][j] << ' ';
// 				cout << '\n';
// 			}
// 			printf("%lld\n", aux[0][0]);
// 		}
// 	}
// }


    #include <bits/stdc++.h>
    using namespace std;
    #define mod 1000000007
    typedef long long ll;
    typedef vector<ll> vi;
    typedef vector<vi> matr;
    	
    	
	int n = 3;
    inline matr mult(matr &A, matr &B, matr &C) {
    	// matr C(A.size());
		ll v;
		// C.resize((int) A.size());
    	for (register int i = 0; i < A.size(); ++i) {
			// C[i].resize(B[0].size());
    		for (int j = 0; j < B[0].size(); ++j) {
    			v = 0;
    			for (register int k = 0; k < A[0].size(); ++k) {
    				v = v+A[i][k]*B[k][j];
					if (v >= mod) v = v % mod;
				}
    			C[i][j] = v;
    		}
		}
    	return C;
    }
    	
    inline void expo(matr& A, ll k, matr& ret) {
      matr resp(n, vi(n)), B = A;
      matr aux(n, vi(n));
      for(int i = 0; i < n; i++) resp[i][i]=1;
     
      while(k) {
        if(k & 1) {
			resp = mult(resp, B, aux);
			swap(resp, aux);
		}
        mult(B, B, aux); k >>= 1;
		swap(B, aux);
    	for(int i = 0; i < n; i++) 
    		for(int j = 0; j < n; j++)
    			if (resp[i][j] >= mod)
    				resp[i][j] = resp[i][j] % mod;
      }
      for(int i = 0; i < n; i++) 
    		for(int j = 0; j < n; j++)
				ret[i][j] = resp[i][j];
    }
    	
    int main(){
    	ll x;
    	int t;
    	scanf("%d", &t);
    	for (int i = 0; i < t; ++i) {
			matr m = {{1,0,0}, {8,5,3}, {5,3,2}};
			matr b = {{2,1,1}};
    		scanf("%lld", &x);
    		if (x == 0)
    			printf("0\n");
    		else if (x == 1) 
    			printf("2\n");
    		else {
				// matr z = expo(m, x-1);
				// for (int i = 0; i < 3; ++i) {
				// 	for (int j = 0; j < 3; ++j)
				// 		cout << z[i][j] << ' ';
				// 	cout << '\n';
				// }
				matr aux(n, vi(n));
				expo(m, x-1,aux);
				mult(b, aux, m);
    			printf("%lld\n", m[0][0]);
			}
    	}
    	
    } 

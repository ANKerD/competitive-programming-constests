#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define INF 1000000000
#define maxn 1010
#define mod 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

int a[maxn][maxn];
int m[maxn][maxn];
int s[maxn][maxn];
int r[maxn][maxn];

int n;

void pr(int arr[maxn][maxn]){
	cout << "-------------\n";
	for(int i = 0; i < n; i++){
		for(int j=0; j < n-i;j++)
			cout << arr[i][j] << ' ';
		cout << "\n";
	}
	cout << "==============\n";
}

int main(){
	cin >> n;
	while(n){
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j <= i; j++){
				cin >> a[i-j][j];
			}
			// ans = max(ans, a[i][0]);
		}
		for(int i = 0; i < n; i++){
			s[i][0]=a[i][0];
			for(int j = 1; j < n-i; j++)
				s[i][j] = s[i][j-1]+a[i][j];
		}

		for(int j = n-1; j >= 0; j--){
			m[0][j] = r[0][j] = s[0][j];
			if(j!=n-1)
				m[0][j] = max(m[0][j], m[0][j+1]);
			// ans = max(ans, r[0][j]);
		}

		for(int i = 1; i<n; i++){
			for(int j = n-i-1; j>= 0; j--){
				r[i][j] = s[i][j]+m[i-1][j];
				// ans = max(ans, r[i][j]);
				
				m[i][j] = r[i][j];
				
				if(j!=n-i-1)
					m[i][j] = max(r[i][j], m[i][j+1]);
			}
		}

		for(int i = 0; i < n; i++)
			for(int j = n-i-1; j>=0; j--)
				ans = max(ans, r[i][j]);
		
		// pr(a);
		// pr(s);
		// pr(r);

		cout << ans << "\n";
		cin >> n;
	}
}
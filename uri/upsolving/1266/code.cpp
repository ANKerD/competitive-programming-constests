#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn -879879

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int a[5055];
int b[5055];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,ans,aux;
	while (true) {
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		ans = 1e9;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				b[j] = a[j];
			aux = 0;
			for (int j = 0; j < n; ++j) {
				if (b[(i+j) % n] + b[(i+j-1+n) % n] == 0) {
					b[(i+j) % n] = 1;
					++aux;
				}
			}
			ans = min(ans, aux);
		}
		trace(ans);
	}
 	return 0;
}


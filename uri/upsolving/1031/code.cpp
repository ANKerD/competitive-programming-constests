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

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		int a[n];
		for(int j = 1; ; j++){
			for(int i = 0; i < n; i++)
				a[i] = i;
			int i = 0;
			int t = n-1;
			while(t--){
				a[i] = -1;
				for(int k = 0; k < j; k++){
					i = (i+1)%n;
					while(a[i] == -1)
						i = (i+1)%n;
				}
			}
			// trace(j);
			if(i == 12){
				cout << j << '\n';
				break;
			}
		}
	}
 	return 0;
}


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
	while(scanf("%d", &n) != EOF){
		int x,y;
		vi a;
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			for(int j = x; j <= y; j++)
				a.pb(j);
		}
		sort(a.begin(),a.end());

		int t;
		cin >> t;
		auto b = a.begin();
		auto r = upper_bound(a.begin(), a.end(), t);
		auto l = lower_bound(a.begin(), a.end(), t);

		if (l == r)
			printf("%d not found\n", t);
		else
			printf("%d found from %d to %d\n", t,  l-b, r-b-1);
	}
 	return 0;
}


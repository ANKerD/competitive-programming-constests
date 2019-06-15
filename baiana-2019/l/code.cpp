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
	for (int i = 0; i < 7; ++i) {
		int ans = 0, x = 0;
		for (int j = 0; j < 7; ++j) {
			cin >> x;
			ans += x;
		}
		printf("%d\n", ans);
	}

 	return 0;
}


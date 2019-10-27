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

inline void rem(int qtd, int &left, int cost, int &ans) {
	while (qtd > 0 && left > 0) {
		left--;
		qtd--;
		ans += cost;
	}
}

int main(){
	int n, ans = 7;
	cin >> n;
	rem(10, n, 0, ans);
	rem(20, n, 1, ans);
	rem(70, n, 2, ans);
	rem(3010, n, 5, ans);
	trace(ans);
	
 	return 0;
}


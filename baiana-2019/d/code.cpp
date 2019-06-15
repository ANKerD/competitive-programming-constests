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

char getd(int d) {
	if (d <= 12) return 'm';
	if (d > 30) return 'a';
	return 'd';
}

int main(){
	int a,b,c, h[3];
	cin >> a >> b >> c;
	h[0] = a;
	h[1] = b;
	h[2] = c;
	sort(h,h+3);
	if (h[1] <= 12 || h[2] <= 30) {
		trace("ambigua");
	} else if (h[0] > 12 || h[1] > 30) {
		trace("invalida");
	} else {
		printf("%c-%c-%c\n", getd(a), getd(b), getd(c));
	}
 	return 0;
}


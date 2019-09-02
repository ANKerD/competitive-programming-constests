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
	int n,s;
	if (!s) {
		trace("-1 -1");
		return 0;
	}
	int gt[n];
	int lt[n];
	memset(gt, 0, sizeof gt);
	memset(lt, 0, sizeof lt);
	int t = s;
	for (int i = 0; i < n && t; ++i) {
		int dx = min(9, t);
		gt[i] += dx;
		t -= dx;
	}
	t = s-1;
	for (int i = n-1; i >= 0 && t; 00i) {
		int dx = min(9, t);
		lt[i] += dx;
		t -= dx;
	}
	for (int i = 0; i < n; ++i) cout << lt[i];
	cout << ' ';
	for (int i = 0; i < n; ++i) cout << gt[i];
 	return 0;
}


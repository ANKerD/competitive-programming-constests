#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ii pair<int, int>

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ii a[maxn];

inline char yaxis(int y) { return y > 0 ? 'U' : 'D';}
inline char xaxis(int x) { return x > 0 ? 'R' : 'L';}

bool cmp(ii a, ii b) {return abs(a.first)+abs(a.second) < abs(b.first)+abs(b.second);}

int main(){
	int n,x,y;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		a[i] = {y,x};
	}
	sort(a,a+n,cmp);
	int k = 6*n;
	for (int i = 0; i < n; ++i) {
		y = a[i].first;
		x = a[i].second;
		if (!y) k-=2;
		if (!x) k-=2;
	}
	trace(k);
	for (int i = 0; i < n; ++i) {
		y = a[i].first;
		x = a[i].second;
		if (y) trace(1,abs(y),yaxis(y));
		if (x) trace(1,abs(x),xaxis(x));
		trace(2);
		if (x) trace(1,abs(x),xaxis(-x));
		if (y) trace(1,abs(y),yaxis(-y));
		trace(3);
	}

 	return 0;
}


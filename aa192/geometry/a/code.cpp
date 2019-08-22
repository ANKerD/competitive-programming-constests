#include <bits/stdc++.h>
#define readpt(a) cin >> x >> y; a = {x,y};
using namespace std;
typedef long double ld;

struct pt {
	ld x,y;
	pt operator - (pt a) {
		return {x-a.x, y-a.y};
	}
	ld operator ^ (pt a) {
		return x * a.y - y * a.x;
	}
};

int main(){
	pt a,b,c;
	ld x,y;
	readpt(a);
	readpt(b);
	readpt(c);
	ld ans = fabs((b-a) ^ (c-a));
	cout << fixed << setprecision(10) << ans << '\n';

 	return 0;
}


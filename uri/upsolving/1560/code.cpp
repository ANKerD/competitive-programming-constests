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
#define PI 3.141592653589793

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

struct pt{
	ld x,y;
};

pt rotate(pt p, ld theta) {
	ld rad = theta * PI / 180.0;
	return {
		p.x * cos(rad) - p.y * sin(rad),
		p.x * sin(rad) + p.y * cos(rad)
	};
}

int main(){
	ld x,y;
	cin >> x >> y;
	pt p = {x,y};
	p = rotate(p, 1.76);
	cout << setprecision(987);
	trace(p.x, p.y);
 	return 0;
}


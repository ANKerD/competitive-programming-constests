#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 2010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

struct L {
	int x1,x2,y;
	L(){};
	L(int _x1, int _x2, int _y){
		x1 = _x1;
		x2 = _x2;
		y = _y;
	};
};


int n,x1,x2,y;
L l[maxn];

ii pivot;
bool cmp(L a, L b){
	return 
		(b.x-pivot.x)*(a.y-pivot.y) < 
		(a.x-pivot.x)*(b.y-pivot.y);
}

L rotate(L ln, ii pt){
	int y  = 2*pt.y - ln.y;
	int x1 = 2*pt.x - ln.x2;
	int x2 = 2*pt.x - ln.x1;
	return L(x1,x2,y);
}

int getansbypoint(ii pt){
	vector<L> r;
	for (int i = 0; i < n; i++){
		if(pt.y == l[line].y) continue;
		
		L ln = l[line].y;
		if(pt.y < ln.y)
			ln = rotate(ln, pt);

		r.pb(r);
	}
	pivot = pt;
}

int solve(int line){
	ii p1 = mp(l[line].x1; l[line].y);
	int ans = getansbypoint(p1);
	p1 = mp(l[line].x2; l[line].y);
	return max(ans, getansbypoint(p1))
}

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			cin >> x >> x2 >> y;
			l[i] = L(x1,x2,y);
		}

		int ans = 0;
		for(int i = 0; i < n; i++)
			ans = max(ans, solve(i));

		printf("%d\n", ans);
	}
 	return 0;
}


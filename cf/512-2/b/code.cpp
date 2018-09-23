#include <bits/stdc++.h>
using namespace std;
#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 2000000
#define mod 1000000007
#define md(x) (x) % mod;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ps push
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF 1000000000
#define INFd 1e9
#define PI 3.141592653589793
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

struct point{
	ld y, x;
	point(ld a, ld b): x(a), y(b) {};
	point operator -(point a){ return point(x-a.x,y-a.y); }
	bool operator == (point p){return x==p.x&&y==p.y;}
};

ld cross(point a, point b){
	return a.x*b.y-a.y*b.x;
}

ld dot(point a, point b){
	return a.x*b.x+a.y*b.y;
}

ld norm_sq(point a){
	return a.x*a.x+a.y*a.y;
}

bool ccw(point p, point q, point r){
	return cross(q-p,r-p)>=0;
}

ld angle(point a, point o, point b){

	point oa = a-o;
	point ob = b-o;
	// trace1(acos(dot(oa, ob)/sqrt(norm_sq(oa)*norm_sq(ob))));
	// trace1(dot(oa, ob));
	// trace1(sqrt(norm_sq(oa)*norm_sq(ob)));
	return acos(dot(oa, ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}

bool inPolygon(point pt, const vector<point> &P){
	if((int)P.size()==0) return 1;
	ld sum = 0;
	for(int i = 0; i < ((int)P.size())-1;i++){
		if(ccw(pt, P[i], P[i+1]))
			sum += angle(P[i], pt, P[i+1]);
		else
			sum -= angle(P[i], pt, P[i+1]);
	}
	// trace1(fabs(fabs(sum)-2*PI));
	// trace2(pt.x,pt.y);
	return fabs(fabs(sum)-2*PI) < EPS;
}

bool inBorder(point pt, const vector<point> &P){
	for(int i = 0; i < 4; i++)
		if(pt == P[i])
			return true;
	return false;
}

int main(){
	int d,n,m;
	cin >> n >> d >> m;
	vector<point> P;
	P.pb(point(d,0));
	P.pb(point(n,n-d));
	P.pb(point(n-d,n));
	P.pb(point(0,d));
	P.pb(point(d,0));
	
	int x,y;
	while(m--){
		cin >> x >> y;
		point lp = point(x,y);
		if(inPolygon(lp, P) || inBorder(lp, P)){
			trace1("YES");
		} else {
			trace1("NO");
		}
	}

 	return 0;
}

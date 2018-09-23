#include <bits/stdc++.h>
#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) for(int i = 0;i< tam;i++) cout << harry[i] << " \n"[i == tam -1];
#define maxn 5000
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
#define INF 100000000
#define INFd 100000000.0
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int q, a, b, c, d, fa, fb;
int n, k = 0, m, t;
bool eq(double d1, double d2) {return fabs(d1-d2) < EPS;}

struct point {double x, y, z;
	point() : x(0.0), y(0.0), z(0.0) {}
    point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    
    bool operator == (point o) const {
        return eq(x, o.x) && eq(y, o.y) && eq(z, o.z);
    }
    bool operator < (point o) const {
        return (eq(x, o.x)) ? (eq(y, o.y) ? z < o.z : y < o.y) : (x < o.x);
    }
};
/*
double cross(point a, point b) {
    return a.x * b.y - b.x * a.y;
}*/
point vec(point a, point b) {
    return point(b.x-a.x, b.y-a.y, b.z-a.z);
}/*
bool collinear(point p, point q, point r) {
    return fabs(cross(vec(p, q), vec(p, r))) < EPS;
}*/
bool col(point p, point q, point r) {
	point pq = vec(p, q);
	point qr = vec(q, r);
	double co;
	if (!(eq(pq.x, 0.0) || eq(qr.x, 0.0))) {
		co = pq.x/qr.x;
	} else if (!(eq(pq.y, 0.0) || eq(qr.y, 0.0))) {
		co = pq.y/qr.y;
	} else if (!(eq(pq.z, 0.0) || eq(qr.z, 0.0))) {
		co = pq.z/qr.z;
	} else {
		return false;
	}
	// pr("co: %lf qr.x %lf qr.y %lf qr.z %lf pq.x %lf pq.y %lf pq.z %lf\n", co, qr.x, qr.y, qr.z, pq.x, pq.y, pq.z);
	qr.x *= co;
	qr.y *= co;
	qr.z *= co;
	// pr("co: %lf qr.x %lf qr.y %lf qr.z %lf pq.x %lf pq.y %lf pq.z %lf\n", co, qr.x, qr.y, qr.z, pq.x, pq.y, pq.z);
	return (eq(pq.x, qr.x) && eq(pq.y, qr.y) && eq(pq.z, qr.z));
	//return eq(pq.x*qr.y*qr.z, qr.x*pq.y*qr.z) && eq(qr.x*pq.y*qr.z, qr.x*qr.y*pq.z);
}
int main() {
    set<point> s;
    sc("%d\n", &n);
    sc("%d %d %d", &a, &b, &c);
    point terra = point(a, b, c);
    for (int i = 1; i < n; i++) {
        sc("%d %d %d", &a, &b, &c);
        s.insert(point(a, b, c));
    }
    int r = 0;
    // pr("s: %d\n", s.size());
    while (!s.empty()) {
        r++;
        set<point>::iterator it = s.begin();
        point b = *it;
		point p = point(b.x, b.y, b.z);
        it++;
        s.erase(p);
        it = s.begin();
        vector<point> vp;
        for (it; it != s.end(); it++) {
            if (col(terra, b, *it)) {
				p = point((*it).x, (*it).y, (*it).z);
                vp.push_back(p);
            }
        }
        for (int i = 0; i < (int)vp.size(); i++) {
            s.erase(vp[i]);
        }
    }
	// for(auto it = rbegin(); it=rend();it++)
    
    pr("%d\n", r);
    return 0;
}

// point cross(point a, point b) {
//     int x = a.y*b.z - a.z*b.y;
// 	int y = a.z*b.x - a.x*b.z;
// 	int z = a.z*b.x - a.x*b.z;
// 	return(x,y,z);
// }
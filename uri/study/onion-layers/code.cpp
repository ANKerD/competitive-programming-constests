#include <bits/stdc++.h>
using namespace std;
#define pb push_back

struct pt {
	int x,y;
	int operator ^ (pt o) { // Produto cruzado |this|*|o|*sin(this->o)
        return x * o.y - y * o.x;
	}
	pt operator - (pt o) { //Diferença de pontos
        return {x - o.x, y - o.y};
	}
	bool operator == (pt o) {
        return x == o.x && y == o.y;
	}
};

inline bool operator<(const pt& a, const pt& b){
  	if(a.x != b.x)  return a.x < b.x;
	else return a.y < b.y;
}

bool ccw(pt p, pt q, pt r) {
	pt p1 = q-p;
	pt p2 = r-p;
	return (p1 ^ p2) > 0;
}

vector<pt> convexhull(vector<pt> points){
	int n = (int) points.size();
	if(n <= 3) return points;

	sort(points.begin(), points.end());

	int k = 0;
	vector<pt> hull(2*n);

	for (int i = 0; i < n; ++i) {
		while (k >= 2 && ccw(hull[k-2], hull[k-1], points[i])) k--;
		hull[k++] = points[i];
	}
	for (int i = n-1, t = k+1; i > 0; --i) {
		while (k >= t && ccw(hull[k-2], hull[k-1], points[i-1])) k--;
		hull[k++] = points[i-1];
	}

	hull.resize(k-1);
	return hull;
}

int main(){
	int n,x,y;
	while (1){
		scanf("%d", &n);
		if (!n)break;
		vector<pt> points;
		for (int i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			points.pb({x,y});
		}
		
		int qtd = 0;
		while ((int) points.size() > 0){
			qtd++;
			vector<pt> hull = convexhull(points);
			set<pt> dots(hull.begin(), hull.end());
			vector<pt> npts;
			for (auto dot: points)
				if (!dots.count(dot))
					npts.pb(dot);

			points = npts;
		}
		
		if(qtd&1)
			printf("Take this onion to the lab!\n");
		else
			printf("Do not take this onion to the lab!\n");
	}

 	return 0;
}
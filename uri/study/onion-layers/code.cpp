#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define ii pair<int, int>
#define vii vector<ii>

bool cmp(ii a, ii b){
	if(a.x != b.x) 
		return a.x < b.x;
	return a.y < b.y;
}

int cross(ii a, ii b) { return a.x * b.y - a.y * b.x; }
ii toVec(ii a, ii b){ return mp(b.x-a.x, b.y-a.y); }

bool ccw(ii p, ii q, ii r) {
	return cross(toVec(p, q), toVec(p, r)) > 0; 
}

vii convexhull(vii pt){
	int n = (int) pt.size();
	if(n <= 3) return pt;

	sort(pt.begin(), pt.end(), cmp);

	int k = 0;
	vii hull(2*n);

	for(int i = 0; i < n; ++i) {
		while (k >= 2 && ccw(hull[k-2], hull[k-1], pt[i])) k--;
		hull[k++] = pt[i];
	}
	// printf("k = %d\n", k);
	for(int i = n-1, t = k+1; i > 0; --i) {
		while (k >= t && ccw(hull[k-2], hull[k-1], pt[i-1])) k--;
		hull[k++] = pt[i-1];
	}

	hull.resize(k-1);
	return hull;
}

int main(){
	int n,x,y;
	while(1){
		cin >> n;
		if(!n)break;
		vii pt;
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			pt.pb(mp(x,y));
		}
		
		int qtd = 0;
		while((int) pt.size() > 0){
			qtd++;
			vii hull = convexhull(pt);
			set<ii> dots(hull.begin(), hull.end());
			vii npts;
			for(auto dot: pt)
				if(!dots.count(dot))
					npts.pb(dot);
			// for(auto dot: pt)
			// 	if(dots.count(dot))
			// 		printf("<%d, %d> ", dot.x, dot.y);
			// cout << "\n\n\n";

			pt = npts;
		}
		// printf("qtd = %d\n", qtd);
		if(qtd&1)
			cout << "Take this onion to the lab!\n";
		else
			cout << "Do not take this onion to the lab!\n";
	}

 	return 0;
}
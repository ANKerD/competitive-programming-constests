#include <bits/stdc++.h>
#define maxn 300010
using namespace std;

struct pt {
	int a,b,i;
};

bool gt(pt &a, pt &b) {
	return a.a < b.a; 
}
bool lt(pt &a, pt &b) {
	return a.a > b.a; 
}

int main(){

	int n,x,y;
	cin >> n;
	vector<pt> g;
	vector<pt> l;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y;
		if (x < y) l.push_back({x,y,i});
		else g.push_back({x,y,i});
	}

	if (l.size() >= g.size()) {
		sort(l.begin(), l.end(), lt);
		cout << l.size() << '\n';
		for (int i = 0; i < l.size(); ++i)
			cout << l[i].i << " \n"[i+1==l.size()];
	}  else {
		sort(g.begin(), g.end(), gt);
		cout << g.size() << '\n';
		for (int i = 0; i < g.size(); ++i)
			cout << g[i].i << " \n"[i+1==g.size()];
	}

 	return 0;
}


int p[maxn];

int find(int x){
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

int join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) p[y] = x;
}

int main(){
	int n,m,x,y,z;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	priority_queue< pair<int, ii> > q;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		q.push({-z, {x,y}});
	}

	int ans = 0;

	while (!q.empty()) {
		int cost = -q.top().fi;
		x = q.top().se.fi;
		y = q.top().se.se;
		q.pop();
		if (find(x) != find(y)) {
			ans += cost;
			join(x,y);
		}
	}
	trace(ans);
 	return 0;
}

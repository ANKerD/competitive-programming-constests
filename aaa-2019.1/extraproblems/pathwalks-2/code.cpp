#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define INF static_cast<int>(1e5+10)
#define maxn 100010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

map<int, int> tree[maxn];

void update(int node, int i, int v){
	// trace("up", node, i);
	while (i < INF) {
		tree[node][i] = max(v, tree[node][i]);
		i += i&-i;
	}
}

int query(int node, int i) {
	int ans = 0;
	while (i) {
		ans = max(ans, tree[node][i]);
		i -= i&-i;
	}
	return ans;
}

int main(){
	int n, m;
	scanf("%d %d\n", &n, &m);
	
	int x,y,z;
	int ans = 1;
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %d\n", &x, &y, &z);
		
		int pt = query(x, z);
		ans = max(ans, pt+1);
		update(y, z+1, pt+1);
	}
	printf("%d\n", ans);
 	return 0;
}


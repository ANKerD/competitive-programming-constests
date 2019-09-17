
 #include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define sc scanf
#define maxn 5050
 
int vis[maxn];
vi g[maxn];
int d[maxn][maxn];
 
int main () {
  int n,m,k,x,y; scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      d[i][j] = i == j ? 0 : 1e9;
 
  queue<ii> q;
  for (int i = 1; i <= min(n,2000); ++i) {
    q.push({i, 0});
    memset(vis, 0, sizeof vis);
    while (!q.empty()) {
      ii top = q.front();
      q.pop();
      vis[top.fi] = 1;
      if (d[i][top.fi] < top.se) continue;
      d[top.fi][i] = d[i][top.fi] = top.se;
      for (auto u: g[top.fi])
        if(!vis[u]) q.push({u, top.se+1});
    }
  }
  int bigDist = 0;
  for (int i = 1; i <= min(n,2000); ++i)
    for (int j = i+1; j <= n; ++j)
      bigDist = max(bigDist, d[i][j]);
  if (n-bigDist >= k) {
    printf("%d\n", n);
    for (int i = 1; i <= n; ++i)
      printf("%d%c", i, " \n"[i == n]);
  } else {
    printf("0\n");
  }
 
  return 0;
}

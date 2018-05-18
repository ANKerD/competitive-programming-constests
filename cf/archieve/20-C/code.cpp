#include <bits/stdc++.h>
#define N_MAX 100500
#define INF 100000000000LL
#define P pair<int, int>
#define ull unsigned long long int
using namespace std;

vector< P > g[N_MAX];
ull d[N_MAX];
int parent[N_MAX];
int n, m, source;

void dijkstra(){
  priority_queue< P, vector< P >, greater< P > > qq;
  qq.push(make_pair(d[source], source));
  while(!qq.empty()){
    int u = qq.top().second;
    int first = qq.top().first;
    qq.pop();
    if(d[u] < first)
      continue;
    for(int i = 0; i < g[u].size(); i++){
      if(d[g[u][i].second] > d[u] + g[u][i].first){
        qq.push(g[u][i]);
        d[g[u][i].second] = d[u] + g[u][i].first;
        parent[g[u][i].second] = u;
      }
    }
  }
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  int x, y, z;
  for(int i = 1; i <= n; i++){
    parent[i] = -1;
    d[i] = INF;
  }

  for(int i = 0; i < m; i++){
    cin >> x >> y >> z;
    g[x].push_back(make_pair(z, y));
    g[y].push_back(make_pair(z, x));
  }

  source = 1;
  d[source] = 0;
  parent[source] = 1;

  dijkstra();

  vector<int> path;
  while(n != 1){
    path.push_back(n);

    if(parent[n] == -1){
      cout << "-1\n";
      return 0;
    }

    n = parent[n];
  }
  cout << 1;
  for(int i = path.size()-1; i >= 0; i--)
    cout << ' ' << path[i];
  cout << '\n';


  return 0;
}

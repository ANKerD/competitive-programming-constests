#include<bits/stdc++.h>
#define N_MAX 300010
// #define p Pair
using namespace std;

vector<int> g[N_MAX];
int sz[N_MAX];
bool bee[N_MAX];
long long int n, f, b;

void siz(int v, int p){
  sz[v] = 1;
  // cout << v << ' ' << u << '\n';
  for(int i = 0; i < g[v].size(); i++){
    int u = g[v][i];
    if(u != p){
      siz(u, v);
      sz[v] += sz[u];
    }
  }
}

void dfs(int v, int p){
  for(int i = 0; i < g[v].size(); i++){
    int u = g[v][i];
    if(u != p){

      if(u == b){
        bee[u] = true;
        if (v != f)
          bee[v] = true;
        return;
      }
      dfs(u, v);
    }
  }
  if (bee[v]){
    if(p != f)
      bee[p] = true;
  }
}

int main(){
  cin >> n >> f >> b;

  int x, y;
  for(int i = 0; i < n-1; i++){
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  siz(f, -1);
  dfs(f, -1);

  long long int s = 1;
  for(int i = 0; i < g[f].size(); i++){
    int u = g[f][i];
    // cout << u << '\n';
    if (!bee[u])
      s += sz[u];
  }

  s *= sz[b];
  cout << n * (n-1) - s << '\n';

  return 0;
}

#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;
pair <int, int> answers[N_MAX];
int qtdAnswer = 0;
bool ok = true;
vector<int> g[N_MAX];
vector<int> roots;
// set<int> used;
// int root = 1;

void dfs(int v, int p){
  if(!ok)
    return;
  if(v != root && g[v].size() > 2){
    ok = false;
    return;
  }
  bool vis = false;
  for(auto u: g[v])
    if(u != p){
      dfs(u, v);
      vis = true;
    }
  if(!vis)
    answers[qtdAnswer++] = make_pair(root, v);
}

int main(){
  ios_base::sync_with_stdio(false);
  int n, x, y;
  cin >> n;
  while(--n){
    cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }

  for(int i = 2; i <=n; i++)
    if(g[i].size() > g[root].size())
      root = i;
  dfs(root, root);
  if(!ok){
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  cout << qtdAnswer << '\n';
  for(int i = 0; i < qtdAnswer; i++)
    cout << answers[i].first << ' ' << answers[i].second << '\n';

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

void remove_leaf(int i, int &k, vector<int> rem, vector<int> g[], bool leaf[]){
  if(k == 0)
    return;
  int p = g[i][0];
  if(leaf[p] && p < i){
    rem.push_back(p);
    k--;
    for(auto u: g[p]){
      for(int j = 0; j < g[u].size(); j++){
        if(g[u][j] == p)
          g[u].erase(g[u].begin()+j);
      }
      if(g[u].size() <= 1)
        leaf[u] = true;
    }
    remove_leaf(p, k, rem, g, leaf);
  }

}

int main(){
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;

  int x,y;

  vector<int> g[n+1];
  bool leaf[n+1];
  memset(leaf, 0, sizeof(leaf));
  for(int i = 0; i < n-1; i++){
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1; i <= n; i++){
    if (g[i].size() <= 1)
      leaf[i] = true;
  }

  vector<int> rem;
  int i = 1;
  while(k > 0){
    while(!leaf[i])
      i++;
    for(auto u: g[i]){
      for(int j = 0; j < g[u].size(); j++){
        if(g[u][j] == i)
          g[u].erase(g[u].begin()+j);
      }
      if(g[u].size() <= 1)
        leaf[u] = true;
    }
    rem.push_back(i);
    k--;
    remove_leaf(i, k, rem, g, leaf);
    i++;
  }


  for(int i = 0; i < rem.size(); i++){
    cout << rem[i];
    if (i < rem.size()-1)
      cout << ' ';
  }
  cout << '\n';

  return 0;
}

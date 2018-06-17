#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;

struct Q {
  int v, i;
}q[110];

bool cmp(Q a, Q b){
  return a.v < b.v;
}

int main(){
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> q[i].v;
    q[i].i = i;
  }

  set<int> ans;
  vector<int> index;

  for(int i = 0; i < n; i++){
    if(!ans.count(q[i].v))
      ans.insert(q[i].v), index.push_back(q[i].i);
    if(ans.size() == k)
      break;
  }

  if (ans.size() < k)
    cout << "NO\n";
  else{
    cout << "YES\n";
    cout << index[0]+1;
    for(int i = 1; i < ans.size(); i++)
      cout << ' ' << index[i]+1;
    cout << '\n';
  }
  return 0;
}

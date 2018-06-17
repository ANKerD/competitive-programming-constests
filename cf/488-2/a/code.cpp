#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> seq;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    seq.push_back(x);
  }
  set<int> a;
  for(int i = 0; i < m; i++){
    int x;
    cin >> x;
    a.insert(x);
  }
  int j = 0;
  vector<int> ans;
  while(j < n){
    if(a.count(seq[j])){
      ans.push_back(seq[j]);
    }
    j++;
  }
  if(ans.size()){
    cout << ans[0];
    for(int i = 1; i < ans.size(); i++)
      cout << ' ' << ans[i];
  }
  cout << '\n';

  return 0;
}

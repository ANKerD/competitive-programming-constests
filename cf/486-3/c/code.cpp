#include <bits/stdc++.h>
#define MAXN 200010
#define P pair<ll, ll>
#define ll long long
#define mp(a, b) make_pair(a, b)
using namespace std;

map<ll, P> ans;
map<ll, map<ll, ll> > why;

int main(){
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n;
  for(int i = 0; i < n; i++){
    ll sum = 0;
    set<int>elements;
    cin >> k;
    int x;
    for(int j = 0; j < k; j++){
      cin >> x;
      sum += x;
      if(!elements.count(x)){
        elements.insert(x);
        why[i][x] = j+1;
      }
    }
    for(set<int>::iterator it=elements.begin(); it != elements.end(); it++){
      if (ans.count(sum - *it)) {
        cout << "YES\n";
        P bef = ans[sum - *it];
        cout << i+1 << ' ' << why[i][*it] << '\n';
        cout << bef.first+1 << ' ' << why[bef.first][bef.second] << '\n';
        return 0;
      } else
        ans[sum - *it] = mp(i, *it);
    }
  }
  cout << "NO\n";

  return 0;
}

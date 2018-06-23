#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int x;
  set<int> a;
  while(n--){
    cin >> x;
    if(x != 0)
      a.insert(x);
  }
  cout << a.size() << '\n';

  return 0;
}

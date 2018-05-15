#include <bits/stdc++.h>
#define N_MAX 100010
#define ull unsigned long long
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  ull n;
  cin >> n;

  ull m[n];
  cin >> m[0];
  for(int i = 1; i < n;i++){
    cin >> m[i];
    m[i] ^= m[i-1];
  }

  ull q, x, y;
  cin >> q;
  while(q--){
    cin >> x >> y;
    ull ans = m[y-1];
    if(x>1)
      ans ^= m[x-2];
    cout << ans << '\n';
  }

  return 0;
}

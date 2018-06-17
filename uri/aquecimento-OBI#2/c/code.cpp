#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;
//
// long double fpow(long double a, int b){
//   if(b == 0) return 1;
//   if(b&1) return a*fpow(a, b-1);
//   return fpow(a*a, b>>1);
// }

int main(){
  ios_base::sync_with_stdio(false);

  int q, k, fx, fy, jx, jy;
  long double m;
  cin >> q;
  while(q--){
    cin >> m >> k;
    char c;
    for(int i = 0; i < k; i++)
      for(int j = 0; j < k; j++){
        cin >> c;
        if(c == 'J')
          jx = i, jy = j;
        else if(c == 'F')
          fx = i, fy = j;
      }
    long double d = sqrt(pow(jx-fx, 2)+pow(jy-fy, 2));
    cout << d << '\n';
    int ans = pow(m, d);
    cout << ans << " dBs\n";
  }

  return 0;
}

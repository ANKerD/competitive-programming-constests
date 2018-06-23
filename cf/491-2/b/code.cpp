#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int a[n];
  int t = 0;
  double lim = 4.5*n;

  for(int i = 0; i < n; i++){
    cin >> a[i];
    t += a[i];
  }

  sort(a, a+n);
  int cnt = 0;
  while(t < lim){
    t -= a[cnt++];
    t += 5;
  }

  cout << cnt << '\n';

  return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  ll a[n];
  ll r[m];
  ll l[m];

  // cin >> a[0];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < m; i++){
    cin >> r[i];
  }

  int i = 0;
  while(r[i] <= a[0]){
    cout << "1 " << r[i] << '\n';
    i++;
  }
  for(int j = 1; j < n && i<m; j++){
    a[j] += a[j-1];
    while(i<m && r[i] <= a[j]){
      cout << j+1 << ' ' << r[i++] - a[j-1] << '\n';
    }
  }

  return 0;
}

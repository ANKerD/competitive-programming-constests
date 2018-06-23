#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  int a, b, c, n;
  cin >> a >> b >> c >> n;
  int ans = a + b - c;

  if(ans >= n || c > a || c > b || c > a+b)
    cout << "-1\n";
  else
    cout << n-ans << "\n";

  return 0;
}

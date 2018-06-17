#include <bits/stdc++.h>
#define MAXN 2018
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int a, m, n;
  cin >> a >> m >> n;
  int x, y;
  bool rain[a+1] = {0};
  int umbr[MAXN];
  memset(umbr, -1, sizeof(umbr));
  for(int i = 0; i < m; i++){
    cin x >> y;
    for(int j = x; j <=y; j++)
      rain[j] = true;
  }
  for(int i = 0; i < n; i++){
    cin x >> y;
    umbr[x] = y;
  }
  int polycarp = 0;
  int brella = -1;
  int cost = 0;
  while(polycarp < a){
    if(rain[polycarp] && brella == -1 && umbr[polycarp] == -1){
      cout << "-1\n";
      return 0;
    }
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve(char arr[][99], int &l, int &r, int &k){
  if (k >= 4) {
    arr[1][l] = '#';
    arr[2][l++] = '#';
    arr[1][r] = '#';
    arr[2][r--] = '#';
    k -= 4;
    return;
  }
  if(k == 3){
    arr[1][l++] = '#';
    arr[1][r--] = '#';
    arr[1][(r+l)/2] = '#';
    k = 0;
    return;
  }
  if(k == 2){
    arr[1][l] = '#';
    arr[2][l++] = '#';
    k = 0;
    return;
  }
  arr[1][(r+l)/2] = '#';
  k = 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;

  cout << "YES\n";

  char ans[4][99];

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < n; j++)
      ans[i][j] = '.';
  }

  int l = 1, r = n-2;

  while(k > 0)
    solve(ans, l, r, k);

    for(int i = 0; i < 4; i++){
      for(int j = 0; j < n; j++)
        cout << ans[i][j];
      cout << '\n';
    }

  return 0;
}

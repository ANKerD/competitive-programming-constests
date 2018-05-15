#include <bits/stdc++.h>
using namespace std;

bool solve(int a[], int r, int n, int &t){
  int change[n];
  int move[n];
  memset(change, 0, sizeof(change));
  memset(move, 0, sizeof(move));
  int i = 2;
  for(; i < n; i++){
    if (a[i] - a[i-1] == r)
      continue;
    if((abs(a[i] - a[i-1]) > abs(r)+1) || move[i] >= 2)
      break;
    if(move[i] == 0){
      if (a[i] - a[i-1] < r){
        a[i]++;
        change[i] = -1;
      } else {
        a[i]--;
        change[i] = 1;
      }
      t++;
    } else {
      if (change[i] == -1){
        a[i]-=2;
        change[i] = 1;
      } else {
        a[i]+=2;
        change[i] = -1;
      }
    }
    move[i]++;
    i--;
  }
  for(int j = 0; j <= i; j++)
    a[j] += change[j];
  if (i==n)
    return true;

  return false;
}

bool is_pa(int a[], int n){
  int r = a[1] - a[0];
  for(int i = 2; i < n; i++){
    if(a[i] - a[i-1] != r)
      return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  if(n <=2){
    cout << "0\n";
    return 0;
  }

  int a[n];
  for(int i = 0; i < n; i++)
    cin >> a[i];

  if(is_pa(a, n)){
    cout << "0\n";
    return 0;
  }
  int ans = n+1;
  for(int i = -1; i <= 1; i++){
    for(int j = -1; j <= 1; j++){
      a[0] += i;
      a[1] += j;
      int t = 0;
      if(solve(a, a[1] - a[0], n, t)){
        ans = min(ans, abs(i) + abs(j) + t);
      }
      a[0] -= i;
      a[1] -= j;
    }
  }
  if (ans == n+1)
    cout << -1;
  else
    cout << ans;
  cout << '\n';

  return 0;
}

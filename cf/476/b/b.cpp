#define N_MAX 101
#include <bits/stdc++.h>
using namespace std;

int n, k;
char m[N_MAX][N_MAX];
int ans[N_MAX][N_MAX];
int row_dots[N_MAX][N_MAX];
int col_dots[N_MAX][N_MAX];

void build_row(){
  for (int i = 0; i < n; i++) {
    row_dots[i][0] = 0;

    if (m[i][0] == '.')
      row_dots[i][0] = 1;
    for (int j = 0; j < n; j++) {
      if (m[i][j] == '.')
        row_dots[i][j] = 1 + row_dots[i][j-1];
      else
        row_dots[i][j] = 0;
    }
  }
}

void build_column(){
  for (int j = 0; j < n; j++) {
    col_dots[0][j] = 0;
    if (m[0][j] == '.')
      col_dots[0][j] = 1;
    for (int i = 1; i < n; i++) {
      if (m[i][j] == '.')
        col_dots[i][j] = 1 + col_dots[i-1][j];
      else
        col_dots[i][j] = 0;
    }
  }
}

void count_places(int i, int j){
  int offset;
  offset = 0;
  while (j + offset < n && offset < k) {
    if (row_dots[i][j + offset] >= k){
      ans[i][j]++;
    }
    offset++;
  }
  offset = 0;
  while (i + offset < n && offset < k) {
    if (col_dots[i + offset][j] >= k){
      ans[i][j]++;
    }
    offset++;
  }
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> k;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ans[i][j] = 0;
      cin >> m[i][j];
    }
  }

  build_row();
  build_column();

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if (m[i][j] == '.')
        count_places(i, j);
    }
  }

  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < n; j++){
  //     cout << ans[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  int maxi = 0, x = 0, y = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if (ans[x][y] < ans[i][j]) {
        x=i;y=j;
        maxi = ans[i][j];
      }
    }
  }
  if (maxi != 0)
    cout << x + 1 << ' ' << y + 1<< '\n';
  else
    cout << 1 << ' ' << 1 << "\n";

  return 0;
}

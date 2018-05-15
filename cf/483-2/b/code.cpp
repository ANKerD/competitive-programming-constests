#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;

bool valid(int i, int j, int n, int m){
  if(i < 0 || i >= n)
    return false;
  if(j < 0 || j >= m)
    return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n>>m;
  unsigned char c[n][m];
  for(int i = 0; i < n;i++)
    for(int j = 0; j < m;j++)
      cin >> c[i][j];
  bool ok = true;
  for(int i = 0; i < n;i++){
    for(int j = 0; j < m;j++){
      if (c[i][j] != '*') {
        int bombs = 0;
        for(int x = -1; x <=1; x++){
          for(int y = -1; y <=1; y++){
            // printf("%d %d %d %d\n", i, j, i+x, j+y);
            if(x == 0 && y == 0)
              continue;
            if (valid(i+x, j+y, n, m)) {
              if(c[i+x][j+y] == '*')
                bombs++;
            }
          }
        }
        if(bombs == 0){
          if(c[i][j] != '.')
            ok = false;
        } else if (c[i][j] == '.' || c[i][j]-48 != bombs){
          ok = false;
          // printf("sec %d %d\n", i, j);
        }
      }
    }
  }

  if(ok)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

void cnt(int a[256][], int i, string &n){
  a[i][0] = 1;
  for(int j = 1; j < n.size(); j++){
    if(n[j] == n[j-1])
      a[i][j] = 1 + a[i][j-1];
    else
  }
  int mx = 0;

}

int main(){
  string kiro, shiro, katie;
  int o[3][300000];



  return 0;
}

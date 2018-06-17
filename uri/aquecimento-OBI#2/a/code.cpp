#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  int q;
  cin >> q;
  while(q--){
    int n;
    cin >> n;
    int num[n];
    int s = 0;
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      if(x&1)
        num[s++] = x;
    }
    sort(num, num+s);
    int l = 0;
    int r = s-1;
    if(s){
      cout << num[r--];
      while(l <= r){
        cout << ' ' << num[l++];
        if(l <= r)
          cout << ' ' << num[r--];
      }
    }
    cout << '\n';
  }
  return 0;
}

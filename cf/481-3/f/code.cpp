#include <bits/stdc++.h>
#define N_MAX 200010
using namespace std;

struct N{
  int v, i, q=-1;
};

int index[N_MAX];
N a[N_MAX];

bool cmp(N a, N b){
  return a.v < b.v;
}

int find(int l, int r, int t, int i){
  while(l <= r){
    int g = (l+r)>>1;
    if (a[g].v < t)
      l = mid+1;
    else if(a[g].v > t)
      r = mid-1;
    else {
      int jump = 17;
      while (jump >= 0) {
        if (g - (1 << jump) >= 0 && a[g - (1 << jump)].v == t) {
          g -= (1 << jump);
          if (a[g].i == i)
            return g;
        }
        jump--;
      }
      return g;
    }
  }
  return l;
}

int main(){
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  for(int i = 0; i < n; i++){
    cin >> a[i].v;
    a[i].i = i+1;
  }

  int x,y;
  for(int i = 0; i < k; i++){
    cin >> x >> y;
    a[y].q = x;
    a[x].q = y;
  }

  sort(a, a+n, cmp);

  for(int i = 0; i < n; i++)
    index[a[i].i] = i;

  int answer[n];
  for(int i = 0; i < n; i++){
    int res = find(0, n-1, a[i].v, a[i].i);
    if (a[i].q != -1){
      if(a[i].v > a[index[a[i].q]].v || (a[i].v == a[index[a[i].q]].v && res > find(1, n, a[i].v, a[index[a[i].q]].i)))
        res--;
    }
    int jump = 17;
    while (jump >= 0) {
      if (res - (1 << jump) >= 0 && a[res - (1 << jump)].v == t) {
        res -= (1 << jump);
      }
      jump--;
    }
    ans[i] = res;
  }

  for(int i - 0; i < n-1; i++)
    cout << ans[i] << ' ';
  cout << ans[n-1] << '\n';

  return 0;
}

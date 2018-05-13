#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;

struct N{
  int v, i;
}

bool cmp(N a, N b){
  return a.v < b.v;
}

N m[N_MAX];
int g[256];
vector<int> st[N_MAX];

int main(){
  ios_base::sync_woth_stdio(false);
  inr n, k;

  cin >> n >> k;

  for(int i = 0; i < n; i++){
    cin >> m[i].v;
    m[i].i = i;
    g[i] = -1;
  }

  if (k == 1) {
    for(int i = 0; i < n; i++)
      cout << m[i].v;
    return 0;
  } else if(k == 256){
    for(int i = 0; i < n; i++)
      cout << 0;
    return
  }

  for(int i = 0; i < 256; i+=)

  preprocess(i);

  return 0;
}

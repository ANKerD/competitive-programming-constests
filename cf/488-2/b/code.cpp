#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;

struct k{
  ll p, c, i;
} night[MAXN];

ll resp[MAXN];

ll ans[10];
int n, m;

bool knight(k a, k b){
  return a.p < b.p;
}

bool sst(int a, int b){
  return a > b;
}

ll insert(int i){
  ll t = night[i].c;
  sort(ans, ans+10, sst);
  ll sum = 0;
  for(int i = 0; i < m; i++)
    sum += ans[i];

  sort(ans, ans+10);
  if(t > ans[0])
    ans[0] = t;
  resp[night[i].i] = t+sum;
  return t + sum;
}

int main(){
  ios_base::sync_with_stdio(false);

  memset(ans, 0, sizeof(ans));
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> night[i].p;
    night[i].i = i;
  }
  for(int i = 0; i < n; i++)
    cin >> night[i].c;
  sort(night, night+n, knight);

  for(int i = 0; i < n; i++)
    insert(i);

  cout << resp[0];
  for(int i = 1; i < n; i++)
    cout << ' ' << resp[i];
  cout << '\n';

  return 0;
}

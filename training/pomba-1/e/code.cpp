#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define sc scanf
#define maxn 1000007

map<int, int> cnt;
int main () {
  int n; scanf("%d", &n);

  for(int i = 0; i < n; i++){
    int x; scanf("%d", &x);
    cnt[x]++;
  }

  int ans = 0;
  for(auto it = cnt.begin(); it != cnt.end(); ++it){
    int v = it->second;
    ans += (v-1);
  }
  printf("%d\n", ans);
  return 0;
}
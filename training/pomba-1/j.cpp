#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define sc scanf
#define MAX 1000007
#define INF 9000000000000000007

map<ll, ll> bigu;
int main () {
  int n; scanf("%d", &n);
  
  ll ini = INF, fim = -INF, teto = 0;
  for(int i = 0; i < n; i++){
      ll x, y; scanf("%lld %lld", &x, &y);
      y++;
      if(bigu.count(x)) bigu[x] = max(bigu[x], y);
      else bigu[x] = y;
      ini = min(x, ini);
      fim = max(x, fim);
      teto = max(y, teto);
  }
  ll larg = abs(ini-fim)+1LL;
  ll alt = teto;

  // ans
  ll size = 2LL*(alt+1LL) + larg;
  ll area = teto*larg;
  ll circ = size + 2LL;
  
  ll actual = -INF;
  ll xis = -INF;
  for(auto it = bigu.begin(); bigu.end() != it; it++){
      ll y = it->second;
      ll x = it->first;
      if(actual == -INF) { 
          actual = y; 
          xis = x;
          continue; 
        }

      if(y <= actual) continue;
      area -= abs(x-xis)*1LL*abs(y-actual);
      actual = y;
      xis = x;
  }

  printf("%lld %lld %lld\n", circ, size, area);
  return 0;
}
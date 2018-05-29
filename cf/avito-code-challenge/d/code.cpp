#include <bits/stdc++.h>
#define N_MAX 100
#define INF 1125899906842623LL
#define ll long long
using namespace std;
ll c[N_MAX];
ll resp[N_MAX][N_MAX][N_MAX];
ll cnt[N_MAX][N_MAX];
ll n;
ll answer = -1;

// ll solve(int l, int r, int k, ll acum){
//   if (r == 1) {
//     ll ans = c[l];
//     for(int i = l+1; i <= r; i++)
//       ans &= c[i];
//     return resp[l][r][k] = ans;
//   }
//   ll ans = -1;
//   for(int i = l; i < r && i < r - k+2; i++){
//
//     ans = max(ans, solve(i+1, r, k-1, count(l, i)));
//   }
//   return resp[l][r][k] = ans;
// }

int main(){
  ios_base::sync_with_stdio(false);
  ll k;
  cin >> n >> k;
  for(int i = 0; i < N_MAX; i++)
    for(int j = 0; j < N_MAX; j++)
      for(int l = 0; l < N_MAX; l++)
        resp[i][j][l] = INF;

  for(ll i = 0; i < n; i++)
    cin >> c[i];
  for(int i = 0; i < n; i++)
    cnt[i][1] = c[i];
  for(int i = 0; i < n; i++)
    for(int j = 2; j <= n - i; j++)
      cnt[i][j] = cnt[i][j-1] + c[i+j-1];
  for(int i = 0; i < n; i++){
    for(int j = 1; j <= n ; j++)
      cout << cnt[i][j] << ' ';
    cout << '\n';
  }
  // cout << solve(0, n-k+1, k) << '\n';
  return 0;
}

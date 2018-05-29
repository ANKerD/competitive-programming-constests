#include <bits/stdc++.h>
#define N_MAX 3003
#define INF 99999999999LL
#define ll long long
using namespace std;

//ll d[N_MAX][N_MAX] = {0};
ll m[N_MAX] = {0};
ll si[N_MAX];
ll ci[N_MAX];

int main(){
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;

  for(ll i=0; i<n; i++)
    m[i] = INF;
  for(ll i=0; i<n; i++)
    cin >> si[i];
  for(ll i=0; i<n; i++)
    cin >> ci[i];

  for(ll i=0; i<n; i++){
    ll best = INF;
    for(ll j=i+1; j<n; j++)
      if(si[j] > si[i])
        best = min(best, ci[i] + ci[j]);

    m[i] = best;
  }
  ll answer = INF;
  for(ll i=0; i<n; i++)
    for(ll j=i+1; j<n; j++)
      if(m[j] != INF && si[i] < si[j])
        answer = min(answer, ci[i] + m[j]);

  if(answer != INF)
    cout << answer << '\n';
  else
    cout << "-1\n";

  return 0;
}

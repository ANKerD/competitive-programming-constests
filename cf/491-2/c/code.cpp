#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll ans;
bool ok(ll k){
  if(k <= 0)
    return 0;

  ll candy = n;
  ll v = 0;
  while(candy){
    v += min(candy, k);
    candy -= min(candy, k);
    candy -= candy/10;
  }

  return 2*v >= n;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  ans = n;

  ll maxok = 1;
  ll minnot = 100000000000000000LL;

  while(maxok <= minnot){
    ll guess = (minnot + maxok)/2;

    if(ok(guess)){
      ans = min(ans, guess);
      minnot = guess-1;
    } else
      maxok = guess+1;
  }

  if(ok(maxok+1))
    ans = min(ans, maxok+1);
  if(ok(maxok))
    ans = min(ans, maxok);

  if(ok(minnot))
    ans = min(ans, minnot);
  if(ok(minnot+1))
    ans = min(ans, minnot+1);

  cout << ans << '\n';

  return 0;
}

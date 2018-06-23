#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;

int cnt = 0;

ll egcd(ll a, ll b, ll *x, ll *y){
  if (a == 0){
    *x = 0, *y = 1;
    return b;
  }

  ll x1, y1;
  ll gcd = egcd(b%a, a, &x1, &y1);

  *x = y1 - (b/a) * x1;
  *y = x1;

  return gcd;
}

ll modinv(ll a, ll m){
  ll x, y;
  egcd(a, m, &x, &y);

  return ((x%m) + m) %m;
}

int main(){
  ios_base::sync_with_stdio(false);

  return 0;
}

#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
#define trace1(a) cout << a << '\n'
#define trace2(a, b) cout << a << ' ' << b << '\n'
#define trace3(a, b) cout << a << ' ' << b << ' ' << c << '\n'
#define trace4(a, b) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'
#define trace5(a, b) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n'
#define trace6(a, b) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n'

#define loop(l, r) for(ll i = l; i <= r; i++)
#define read(l, r, a) for(ll i = l; i <= r; i++) cin >> a[i];
#define readGraph(l, r, g) for(ll i = l; i <= r; i++){ ll x, y; cin >> x >> y; g[x].push_back(y); g[y].push_back(x);}

using namespace std;

struct V {
  ll x, y, i;
  // bool add;
};

V mat[MAXN];
int ans[MAXN];
long double ord[MAXN];

bool cmp(V a, V b){
  return ord[a.i] < ord[b.i];
}

// ll lim = 2250000000000;

ll inline p(ll u){
  return u*u;
}

int main(){
  ios_base::sync_with_stdio(false);
  ll n;
  cin >> n;

  loop(0, n-1) {
    cin >> mat[i].x >> mat[i].y;
    mat[i].i = i;
    ord[i] = atan2(mat[i].x, mat[i].y);
  }

  sort(mat, mat+n, cmp);
  ll sx = 0,sy = 0;
  loop(0, n-1){
    if(p(sx+mat[i].x) + p(sy+mat[i].y) < p(sx-mat[i].x) + p(sy-mat[i].y)){
      sx += mat[i].x;
      sy += mat[i].y;
      ans[mat[i].i] = 1;
    } else {
      sx -= mat[i].x;
      sy -= mat[i].y;
      ans[mat[i].i] = -1;
    }
  }

  cout << ans[0];
  loop(1, n-1) cout << ' ' << ans[i];
  cout << '\n';

  return 0;
}

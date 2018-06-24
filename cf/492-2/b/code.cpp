#include <bits/stdc++.h>
#define MAXN 100010
#define trace1(a) cout << a << '\n'
#define trace2(a, b) cout << a << ' ' << b << '\n'
#define trace3(a, b) cout << a << ' ' << b << ' ' << c << '\n'
#define trace4(a, b) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'
#define trace5(a, b) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n'
#define trace6(a, b) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n'

#define loop(l, r) for(int i = l; i <= r; i++)
#define iloop(l, r) for(int i = l; i >= r; i--)
#define read(l, r, a) for(int i = l; i <= r; i++) cin >> a[i];
#define readGraph(l, r, g) for(int i = l; i <= r; i++){ int x, y; cin >> x >> y; g[x].push_back(y); g[y].push_back(x);}

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int l = 1000000009;
  int index = -1;
  int a[n+1];
  int ans[n+1];
  loop(0, n-1){
    cin >> a[i];
    if(a[i]-i <= 0){
      index = i;
      break;
    }
  }
  if(index != -1){
    trace1(index+1);
    return 0;
  }
  iloop(n-1, 0)
    if( a[i] / n <= l)
      l = a[i] / n, index=i;

  trace1(index+1);

  return 0;
}

#include <bits/stdc++.h>

#define MAXN 100010

#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) loop1(0, tam-1) cout << harry[i] << " \n"[i == tam -1]);

#define swap(a, b) auto temp = a; a = b; b = temp;

#define loop1(l, r) for(int i = l; i <= r; i++)
#define loop2(l, r) for(int j = l; j <= r; j++)
#define loop3(l, r) for(int k = l; k <= r; k++)
#define iloop1(l, r) for(int i = l; i >= r; i--)
#define iloop2(l, r) for(int j = l; j >= r; j--)
#define iloop3(l, r) for(int k = l; k >= r; k--)
#define range(sz) loop1(0, sz-1)

#define read(l, r, a) for(int i = l; i <= r; i++) scanf("%d", &a[i])

#define mp(a, b) make_pair(a, b);

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<ll> vll;
typedef vector<double> vd;

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  ll a[MAXN];
  map<int, int> f;
  set<int> o;
  cin >> n;
  ll mini = 1e11;
  loop1(0, n-1){
    cin >> a[i];
    mini = min(mini, a[i]);
    f[a[i]]++;
    o.insert(a[i]);
  }
  int cnt = 0;
  int ans = 0;

  for(auto i = o.begin(); i != o.end(); i++){
    if(cnt){
      int rem = min(cnt, f[*i]);
      ans += rem;
      cnt -= rem;
    }
    cnt += f[*i];
  }
  trace1(ans);

  return 0;
}

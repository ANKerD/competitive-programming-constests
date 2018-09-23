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

struct T{
  int n[3];
  T(int &a, int &b, int &c){
    n[0] = a;
    n[1] = b;
    n[2] = c;
    sort(n, n+3);
    a = n[0];
    b = n[1];
    c = n[2];
  }
};

int cnt[MAXN];

void factor(){
  loop1(1, MAXN-1){
    cnt[i] = 0;
    // if(i > 1)
    //   cnt[i]++;
    loop2(1, sqrt(i))
      if(i % j == 0)
        cnt[i]++;
    if(cnt[i] > 1)
      cnt[i]--;
  }
}

int main(){
  factor();
  int n, a, b, c;
  cin >> n;
  trace1(cnt[100]);
  loop1(0, n-1){
    cin >> a >> b >> c;
    // T m = T(a, b, c);
    // trace1(m.n[1] * m.n[2] * m.n[0]);
    ll m = cnt[a] * cnt[b] * cnt[c];
    trace6(a, cnt[a], b, cnt[b], c, cnt[c]);
    // if(a == b && b == c)
    //   m /= 6;
    // else if(a == b || b == c)
    //   m /= 2;
    trace1(m+1);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ii pair<int, int>
#define ld long double
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define sc scanf
#define maxn -1982979

struct pt {
  ld x, y;
  pt operator - (pt o) {
    return {x - o.x, y - o.y};
  }
  pt operator + (pt o) {
    return {x + o.x, y + o.y};
  }
  pt operator / (ld d) {
    return {x / d, y / d};
  }
  pt operator * (ld d) {
    return {x * d, y * d};
  }
  ld operator ^ (pt o) {
    return x * o.y - y * o.x;
  }
  ld half() {
    return x*x + y*y;
  }
  ld dist() {
    return sqrt(half());
  }
  pt versor() {
    return *this / dist();
  }
};

struct line {
  pt a, b;
  pt versor() {
    pt vec = b-a;
    return vec.versor();
  }
  pt walk(ld x) {
    return a + versor() * max(x, .0L);
  }
};

ostream& operator <<(ostream& o, const pt &p) {
  return o << "(" << p.x << ", " << p.y << ")\n";
}

pt A,B,C;

inline void read(pt &p) {
  cin >> p.x >> p.y;
}

inline void read(int &n, vector<pt> &v, pt O, pt P) {
  ld dis;
  line dir = {O, P};
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> dis;
    v.push_back(dir.walk(dis));
    // cout << v.back();
  }
  // cout << "-----\n";
}

ld get(pt a, pt b, vector<pt> &v, vector<pt> &s) {
  ld ans = 0;
  for (auto u: v)
    ans = max(ans, fabs((b-a) ^ (u-a)));
  for (auto u: s)
    ans = max(ans, fabs((b-a) ^ (u-a)));
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  read(A);
  read(B);
  read(C);
  int a,b,c;
  vector<pt> va, vb, vc, v;
  read(a, va, A, B);
  read(b, vb, B, C);
  read(c, vc, C, A);

  ld ans = 0;
  v.push_back(va[0]);
  v.push_back(vb[0]);
  v.push_back(vc[0]);
  v.push_back(va.back());
  v.push_back(vb.back());
  v.push_back(vc.back());
  for (auto q: v)
    for (auto w: v)
      for (auto e: v)
        ans = max(ans, fabs((w-q) ^ (e-q)));

  // if (a == b && b == c && c == 1) {
  //   ans = fabs((vb[0] - va[0]) ^ (vc[0] - va[0]));
  // } else {
  //   if (a-1) ans = max(ans, get(va[0], va.back(), vb, vc));
  //   if (b-1) ans = max(ans, get(vb[0], vb.back(), vc, va));
  //   if (c-1) ans = max(ans, get(vc[0], vc.back(), va, vb));
  // }

  cout << fixed << setprecision(19) << ans/2.0 << '\n';
  return 0;
}
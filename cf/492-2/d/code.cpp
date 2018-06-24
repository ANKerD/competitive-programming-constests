#include <bits/stdc++.h>

#define MAXN 100010

#define trace1(a) printf("%d\n", a);
#define trace2(a, b) printf("%d %d\n", a);
#define trace3(a, b, c) printf("%d %d %d\n", a);
#define trace4(a, b, c, d) printf("%d %d %d %d\n", a);
#define trace5(a, b, c, d, e) printf("%d %d %d %d %d\n", a);
#define trace6(a, b, c, d, e, f) printf("%d %d %d %d %d %d\n", a);
#define printArr(harry, tam) loop1(0, tam-1) printf("%d%c", harry[i], " \n"[i == tam -1]);

#define swap(a, b) a^= b; b^= a; a^= b;
#define swap2(a, b) auto temp = a; a = b; b = temp;

#define loop1(l, r) for(int i = l; i <= r; i++)
#define loop2(l, r) for(int j = l; j <= r; j++)
#define loop3(l, r) for(int k = l; k <= r; k++)
#define loop4(l, r) for(int m = l; m <= r; m++)
#define loop5(l, r) for(int o = l; o <= r; o++)
#define loop6(l, r) for(int p = l; p <= r; p++)
#define iloop1(l, r) for(int i = l; i >= r; i--)
#define iloop2(l, r) for(int j = l; j >= r; j--)
#define iloop3(l, r) for(int k = l; k >= r; k--)
#define iloop4(l, r) for(int m = l; m >= r; m--)
#define iloop5(l, r) for(int o = l; o >= r; o--)
#define iloop6(l, r) for(int p = l; p >= r; p--)

#define read(l, r, a) for(int i = l; i <= r; i++) scanf("%d", &a[i])
#define readM(l, r, ll, rr, a) for(int i = l; i <= r; i++) for(int j = ll; j <= rr; j++) scanf("%d", &a[i][j])
#define readGraph(l, r, g) for(int i = l; i <= r; i++){ int x, y; cin >> x >> y; g[x].push_back(y); g[y].push_back(x);}

#define pb(ve, value) ve.push_back(value);
#define mp(a, b) make_pair(a, b);
#define fis first;
#define sec second;

using namespace std;

typedef long long ll;
typedef long double ld;

typedef std::pair<int, int> ii;
typedef std::vector<int> vi;
typedef std::vector<ii> vii;
typedef std::vector<vi> vvi;
typedef std::vector<vii> vvii;

typedef std::vector<char> vc;
typedef std::vector<std::vector<char>> vvc;

typedef std::vector<ll> vll;
typedef std::vector<double> vd;

typedef std::string ss;

int arr[220];
int n;

int insert(int t){
  int a, b, res;
  loop1(0, 2*n -1){
    if (arr[i] != t)
      continue;
    a = i;
    loop2(i+1, 2*n -1)
      if (arr[j] != t)
        continue;
      else{
        b = j;
        break;
      }
    res = b - a-1;
    while(a+1 < b){
      swap(arr[b-1], arr[b]);
      b--;
    }
    break;
  }
  return res;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin >> n;
  read(0, 2*n-1, arr);
  bool vis[n+1];
  memset(vis, 0, sizeof(vis));
  int cnt = 0;
  loop(0, 2*n-1){
    if(!vis[arr[i]]){
      cnt += insert(arr[i]);
      vis[arr[i]] = 1;
    }
  }

  trace1(cnt);
  return 0;
}

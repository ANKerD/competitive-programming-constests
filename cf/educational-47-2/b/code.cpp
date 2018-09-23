#include <bits/stdc++.h>

#define MAXN 100010

#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) loop1(0, tam-1) cout << harry[i] << " \n"[i == tam -1]);

#define swap(a, b) a^=b;b^=a;a^=b;

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

int cmp(int a, int b){
  // trace2(a, b);
  // return a-b;
  if(abs(a-b) == 2)
    return 0;
  return a < b;
}

int main(){
  string s;
  int arr[MAXN];
  cin >> s;
  int t = s.size();
  loop1(0, t)
    arr[i] = s[i] -'0';
  // reverse(arr, arr+t);
  // stable_sort(arr, arr+t, cmp);
  // reverse(arr, arr+t);
  // queue<int> q;
  // q.push(0);
  // while(!q.empty()){
  //   int i = q.front();
  //   int st = i;
  //   q.pop();
  //   int cnt = 0;
  //   while(i < t-1 && abs(arr[i] - arr[i+1]) < 2)
  //     i++, cnt;
  //
  //   sort(arr+st, arr+i+1);
  //   if(cnt){
  //     q.push(i+1);
  //     q.push(0);
  //   }
  // }

  bool swaped=1;
  while(swaped){
    swaped = 0;
    loop1(0, t-1){
      // printArr(arr, t);
      if(arr[i] - arr[i+1] == 1){
        swap(arr[i], arr[i+1]);
        swaped = 1;
        i--;
      }
    }
  }

  loop1(0, t-1)
    cout << arr[i];
  cout << "\n";

  return 0;
}

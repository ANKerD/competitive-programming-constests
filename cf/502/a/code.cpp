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

struct S{
	int index;
	int n[4];
	int m(){
		int sum=0;
		range(4){
			sum +=n[i];
		}
		return sum;
	}
};

typedef long long ll;
typedef long double ld;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<ll> vll;
typedef vector<double> vd;

bool cmp(S a, S b){
	if(a.m() == b.m())
		return a.index < b.index;
	return a.m() > b.m();
}

int main(){
	S s[1001];
	int n;

	cin >> n;
	range(n){
		cin >> s[i].n[0];
		cin >> s[i].n[1];
		cin >> s[i].n[2];
		cin >> s[i].n[3];
		s[i].index = i;
	}
	sort(s, s+n, cmp);

	int ans;
	range(n){
		if(s[i].index == 0)
			ans=i;
	}

	trace1(ans+1);


 return 0;
}

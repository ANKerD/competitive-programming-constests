#include <bits/stdc++.h>
using namespace std;
#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 200009
#define mod 1000000007
#define md(x) (x) % mod;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ps push
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF 1000000000
#define INFd 1e9
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

int a[maxn];
int f[maxn];

int main(){
	int n, k;
	cin >> n >> k;
	memset(f,0,sizeof f);
	set<int> s;
	range(n){
		cin >> a[i];
		f[a[i]]++;
		s.insert(a[i]);
	}

	vii m;
	for(auto it = s.begin(); it!=s.end(); it++){
		m.push_back(mp(f[*it], *it));
	}

	sort(m.begin(), m.end());
	reverse(m.begin(), m.end());

	vi ans, tmp;
	int t=1;
	while(true){
		
		// trace1("Hi");
		int left = k;
		for(auto it = m.begin(); it!=m.end(); it++){
			int lt = min(left,(it->first)/t);
			left -= lt;
			range(lt){
				tmp.push_back(it->second);
				// trace1(it->second);
			}
			if(lt<1) break;
			// trace1("(------------");
		}
		t++;
		// ans = tmp;
		if(left){
			printArr(ans, (int)ans.size());
			break;
		}
		ans.clear();
		for(auto it = tmp.begin(); it!=tmp.end(); it++)
			ans.pb(*it);
		tmp.clear();
	}
	// trace1("fdg");
	// printArr(tmp, (int)tmp.size());
	// for(int i = 0; i < (int)ans.size();i++)
	// 	printf("%d%c", ans[i], " \n"[i==n-1]);
		
 	return 0;
}

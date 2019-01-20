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
#define maxn 2000000
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

int getValue(string &b){
	int ab = 0;
	for(int j = 0; j < ((int) b.size()); j++){
		if(b[j] == ')') ab++;
		else ab--;
	}
	return ab;
}

int main(){
	int n;
	cin >> n;
	map<int, ll> a;
	string b;
	ll ans = 0;
	int ab;
	vi nums;
	set<string> ss;
	set<string> used;
	for(int i = 0; i < n; i++){
		cin >> b;
		if(ss.find(b) != ss.end() && getValue(b) == 0 && used.find(b) == used.end()){
			ans++;
			used.insert(b);
		}
		ss.insert(b);
	}
	for(auto it = ss.begin(); it != ss.end(); it++){
		string b = *it;
		ab = getValue(b);
		a[ab]++;
		nums.pb(ab);
	}
	sort(nums.begin(), nums.end());
	for(int i = 0; i < n; i++){
		// trace3(nums[i], a[nums[i]], a[-nums[i]]);
		if(nums[i] > 0) break;
		if(!nums[i]){
			ans += a[0]*(a[0]-1)/2;
			break;
		}
		ans += a[-nums[i]];
	}
		
	trace1(ans);
	
 	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 2000000
#define mod 1000000007
#define md(x) (x) % mod;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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

template<typename T>
void trace(T a){
	cout << a << '\n';
}

template<typename T, typename... Args>
void trace(T a, Args... args){
	cout << a << ' ';
	trace(args...);
}

int cnt[26];

int main(){
	string a;
	cin >> a;
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; i < (int) a.size(); i++)
		cnt[a[i]-'a']++;
	int pt = 0;
	for(int i = 0; i < 26; i++)
		if(cnt[i])
			pt++;
	if(pt == 1)
		trace("Impossible");
	else if((int) a.size() % 2 == 0)
		trace(1);
	else
		trace(2);

 	return 0;
}

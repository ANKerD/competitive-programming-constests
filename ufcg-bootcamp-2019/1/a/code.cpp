#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 1000010
#define mod 1000000007
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

char ss[maxn], tt[maxn];
string s,t;

int f[266];

int main(){
	memset(f,0, sizeof f);
	scanf(" %s", ss);
	scanf(" %s", tt);

	s = ss;
	t = tt;

	register int id;
	register int sz = (int) t.size();

	char m = 'a';
	for(register int i = 0; i < (int) s.size(); i++){
		if(s[i] != '?'){
			f[s[i]]++;
			if(f[s[i]] < f[m]) m = s[i];
		}
	}

	
	for(register int i = 0; i < (int) t.size(); i++){
		f[t[i]]--;
		if(f[t[i]] < f[m]) m = t[i];
	}
	
	char c;
	for(register int i = 0; i < (int) s.size(); i++){
		int id = i % ((int) t.size());
		if(s[i] != '?'){
			c = s[i];
			
		} else {
			c = m;
			f[c]++;
		}
		
		printf("%c",c);
		if(f[c] < f[m]) m = c;
	}

	printf("\n");

 	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define INF 1000000000
#define maxn 100010
#define mod 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

template<typename T>
void trace(T a){
	cout << a << "\n";
}

template<typename T, typename... Args>
void trace(T a, Args... args){
	cout << a << " ";
	trace(args...);
}

char ch[maxn];
int ans[maxn];
string st;
int n;

int gcd(int a, int b){
	if(!a) return b;
	return gcd(b%a,a);
}

int solve(int i){
	int id=i;
	i = gcd(i,n);
	if(ans[i]!=-1)return ans[i];
	int ok = 1;
	for(int j = 0; j < i; j++){
		int k = j;
		ok = 1;
		do {
			if(st[k]=='P'){
				ok = 0;
				break;
			}
			k = (k+i)%n;
		} while(k != j);
		if(ok) return ans[i] = ans[id] = 1;
	}
	return ans[i] = ans[id] = 0;
}

int main(){
	while(scanf(" %s", ch) != EOF){
		st = ch;
		n = (int) st.size();
		memset(ans, -1,sizeof(ans));
		int r = 0;
		for(int i = 1; i <n;i++){
			ans[i] = solve(i);
			r+=ans[i];
		}
		trace(r);
	}

	return 0;
}

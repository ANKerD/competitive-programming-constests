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
#define pr(a,l,r) for(int i = l; i<= r; i++) cout <<a[i]<<" \n"[i==r];

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

ll vowels[255];
ll s[maxn];

string st;
ll solve(int l, int r, bool inv){
	if(l == r) return 1;
	if(inv) swap(l,r);

	ll ret;
	
	if(vowels[st[l]]){
		if(vowels[st[r]]){
			if(inv) swap(l,r);
			ret = solve(l+inv, r-!inv, !inv);
		} else {
			if(inv) swap(l,r);
			ret = solve(l+inv,r-!inv,inv)+solve(l+!inv, r-inv, !inv);
		}
	} else {
		if(vowels[st[r]])
			ret = 0;
		else {
			if(inv) swap(l,r);
			if(l) ret = s[r]-s[l-1] == 0;
			else ret = s[r-inv] == 0;
		}

	}
	trace(l,r,inv, ret);
	return ret;
}

int main(){
	memset(vowels, 0, sizeof vowels);
	vowels['a']=1;
	vowels['e']=1;
	vowels['i']=1;
	vowels['o']=1;
	vowels['u']=1;
	while(cin >> st){
		memset(s,0, sizeof s);
		for(int i = 0; i<((int)st.size()); i++){
			s[i] = static_cast<int>(vowels[st[i]]);
			if(i){
				s[i] = static_cast<int>(s[i]) + static_cast<int>(s[i-1]);
				// trace(i, s[i]);
			}
		}
		// trace(st.size());
		// pr(s,0,st.size()-1);
		trace(solve(0,((ll)st.size())-1, 0));
	}

	return 0;
}

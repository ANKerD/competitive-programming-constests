#include <bits/stdc++.h>
#define maxn 1000101
using namespace std;
typedef long long ll;

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

bool a[maxn];
bool b[maxn];
string s;
ll x, y;

int main(){
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	cin >> s;
	cin >> x >> y;
	int n = s.size();
	ll cur = 0;
	for (ll i = 0; i < n-1; ++i) {
		cur = (10LL*cur + (s[i]-'0')) % x;
		a[i] = cur == 0;
	}
	cur = 0;
	ll p10 = 1;
	for (int i = n-1; i > 0; --i) {
		cur = (cur + (s[i]-'0') * p10) % y;
		p10 = p10 * 10LL % y;
		b[i] = s[i] != '0' && cur == 0;
	}
	for (ll i = 0; i < n-1; ++i) 
		if (a[i] && b[i+1]) {
			trace("YES");
			for (int j = 0; j <= i; ++j) cout << s[j];
			cout << '\n';
			for (int j = i+1; j < n; ++j) cout << s[j];
			cout << '\n';
			return 0;
		}
	
	trace("NO");
 	return 0;
}


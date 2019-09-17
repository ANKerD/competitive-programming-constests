#include <bits/stdc++.h>
using namespace std;
#define maxn 100010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}
 
int get(char a, char b) {
	int x1 = a - 'a';
	int x2 = b - 'a';
	return min((x1 - x2 + 26) % 26, (x2 - x1 + 26) % 26);
}
 
int main() {
	int n, p;
	cin >> n >> p;
	p--;
	if (p * 2 > n - 1)
		p = n - 1 - p;
	string s;
	cin >> s;
	int l = n, r = 0;
	int ans = 0;
	for (int i = 0; i < n / 2; i++)
		if (get(s[i], s[n - 1 - i]) != 0) {
			ans += get(s[i], s[n - 1 - i]);
			l = min(l, i);
			r = max(r, i);
		}
	if (l <= r)
		ans += min(abs(p - l), abs(r - p)) + r - l;
	trace(ans);
		
}
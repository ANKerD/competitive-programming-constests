#include <bits/stdc++.h>
using namespace std;
#define maxn 110

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

stack<int> s[maxn];
int n, a[maxn];

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a,a+n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i] >= s[j].size()) {
				s[j].push(a[i]);
				break;
			}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans += !s[i].empty();
	trace(ans);

 	return 0;
}


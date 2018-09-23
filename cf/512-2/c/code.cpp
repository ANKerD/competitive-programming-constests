#include <bits/stdc++.h>
using namespace std;
#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
int n;
string t;

bool solve(int i, int acum){
	if(i>n) return 0;
	int as = 0;
	while(i < n & as <acum){
		as += t[i++]-'0';
	}
	while(i < n && t[i]=='0') i++;
	if(i == n) return as == acum;
	return solve(i, acum);
}

int main(){	
	cin >> n >> t;
	bool ans = 0;
	int acum = 0;
	int i = 0;
	while(i < n && t[i]=='0')i++;
	if(i==n){
		trace1("YES");
		return 0;
	}
	for(; i<n-1;i++){
		acum += t[i]-'0';
		if(solve(i+1, acum)){
			trace1("YES");
			return 0;
		}
	}
	trace1("NO");
 	return 0;
}

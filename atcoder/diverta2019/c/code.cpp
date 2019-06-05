#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, ans = 0, a=0, b=0, c=0;
	cin >> n;
	string s;
	while(n--){
		cin >> s;
		int x = (int) s.size();
		for (int i = 1; i < x; i++)
			if (s[i] == 'B' && s[i-1] == 'A') ans++;

		if(s[0] == 'B' && s[x-1] == 'A') c++;
		else {
					
			if(s[0] == 'B') b++;
			if(s[x-1] == 'A') a++;
		}
	}

	int x = min(a,b);
	ans += x;
	a-=x;
	b-=x;
	if(c > 1){
		ans += c-1;
		c = 1;
	}

	if(c&&a) ans++;
	if(c&&b) ans++;

	cout << ans << '\n';
 	return 0;
}


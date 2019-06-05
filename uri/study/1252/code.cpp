#include <bits/stdc++.h>
using namespace std;
int n, m;

bool cmp(int a, int b){
	int x = a%m;
	int y = b%m;
	// if (x < 0) x+=m;
	// if (y < 0) y+=m;
	if (x != y) return x < y;
	if (a % 2 == 0 ^ b % 2 == 0)
		return a % 2 != 0;
	if (a % 2 != 0) return a>b;
	return a<b;
}

int main(){
	while(1){
		cin >> n >> m;
		cout << n << ' ' << m << '\n';
		if (n+m == 0)
			break;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a,a+n, cmp);
		for (int i = 0; i < n; i++)
			cout << a[i] << '\n';
	}
 	return 0;
}


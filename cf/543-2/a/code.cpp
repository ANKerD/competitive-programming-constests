#include <bits/stdc++.h>
using namespace std;
int v[101];
int s[101];
int enrol[101];

int main(){
	int n,m,k,x;
	memset(v, 0, sizeof v);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}

	for(int i = 1; i <= n; i++){
		cin >> x;
		enrol[i] = x;
		if(v[i] > v[s[x]])
			s[x] = i;
	}

	int cnt = 0;
	for(int i = 0; i < k; i++){
		cin >> x;
		if(s[enrol[x]] != x)
			cnt++;
	}
		
	printf("%d\n", cnt);

 	return 0;
}

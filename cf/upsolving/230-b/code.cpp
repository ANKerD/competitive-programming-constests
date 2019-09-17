#include <bits/stdc++.h>
using namespace std;
#define maxn 1001000
bitset<maxn> p;
int main(){
	p.set();
	set<long long> num;
	register long long i = 2;
	register long long j;
	while(i < maxn) {
		num.insert(i*i);
		j = i<<1;
		while (j < maxn) {
			p[j] = 0;
			j += i;
		}
		i++;
		while (i < maxn && !p[i]) ++i;
	}
	int n;
	cin >> n;
	long long inp;
	for (int i = 0; i < n; ++i){
		cin >> inp;
		if (num.count(inp))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
 	return 0;
}


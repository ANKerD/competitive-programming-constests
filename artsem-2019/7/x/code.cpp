#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, n;
	cin >> n;
	while(n--){
		cin >> x;
		int s = x+1;
		if(s == (s&-s))
			cout << "1\n";
		else {
			int z = log2(x);
			cout << (1 << (z+1))-1 << '\n';
		}
	}
 	return 0;
}

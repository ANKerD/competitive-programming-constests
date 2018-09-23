#include <iostream>
#include <cstring>
#define MAXN 1000010

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	register int t,a,b, bb, i,j, nd, p, offset;
	cin >> t;
	// scanf("%d", &t);
	while(t--){
		cin >> a >> b;
		offset=0, p=0, nd=0;
		j=0;
		bb=b;
		while(j < a/2 && bb >= 18){
			j++;
			nd++;
			cout << 9;
			bb-=18;
		}
		if(j < a/2){
			if(bb >= 1){
				// p=1;
				// cout << (p=bb/2);
				// bb -= 18;
				j++;
			}

		}
		if(a&1) cout << bb/2*2;
		// for(i=0; i<offset;i++) cout << 0;
		// if(bb/2) cout << bb/2;
		// for(i=0; i<nd;i++) cout << 9;

		cout << '\n';
	}
 	return 0;
}

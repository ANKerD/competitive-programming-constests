#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll q,x,y, k;
	cin >> q;
	while(q--){
		cin >> x >> y >> k;
		x=abs(x);
		y=abs(y);
		if(max(x,y) > k){
			cout << "-1\n";
		} else {
			ll ans = k;
			if((x&1)==(y&1)){
				if((x&1)!=(k&1))
					ans-=2;
			} else {
				ans--;
			}
			cout << ans << "\n";
		}
	}

 	return 0;
}

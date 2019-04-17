#include <bits/stdc++.h>
using namespace std;

int get(int n){
	int i = 1;
	int ans = 0;
	while(n){
		if(n%10)
			ans += i;
		i*=10;
		n /= 10;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
    int sz = 1;
    int x = n;
    while(x){
        sz = max(sz,x%10);
        x/=10;
    }
    cout << sz << '\n';
    while(n > 0){
        cout << get(n);
        n -= get(n);
        cout << " \n"[n==0];
    }
	
	return 0;
}
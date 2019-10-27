#include<bits/stdc++.h>
using namespace std;

int main(){	
	int n,l,c;
	while(cin >> n >> l >> c){
		int cnt = 0, z = 0, lines = 1;
		string s;
		cin >> s;
		int sz = s.size();

		cnt = sz;
		
		for(int i = 1; i < n; i++){
			cin >> s;
			sz = s.size();
			if((sz+1+cnt) <= c){
				cnt += 1+sz;
			} else {
				cnt = sz;
				lines++;
			}
		}

		cout << (lines+l-1)/l << '\n';
	}
	return 0;
}
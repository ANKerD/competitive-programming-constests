#include <bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;
	
	for (int i=0; i<t; i++){
		long long x;
		cin>>x;
		
		if (x%3==0){
			cout<<x/3<<" "<<x/3<<" "<<x/3<<endl;
		}
		
		else if (x%4==0){
			cout<<x/2<<" "<<x/4<<" "<<x/4<<endl;
		}
		else cout <<"IMPOSSIBLE"<<endl;
	
	}


}

#include <bits/stdc++.h>
using namespace std;


long long gcd(long long a, long b){
	if (a==0) return b;
	return gcd(b%a,a);
}

long long lcm(long long a, long long b){
	return a/gcd(a,b)*b;
}


int main(){
	string s;

	while (cin>>s){
		vector<pair<int, int> > g;
		stack<int> pilha;
		int acumulado=1;
		int passado=0;
		int cont=0;
		int p=0;
		char last='+';
		while (p<s.size()){
			int i=p;
			p++;
			if (s[i]-'0'>0 and s[i]-'0'<10 or s[i]=='0' and (s[i+1]-'0'>9 or s[i+1]-'0'<0)){
				//cout<<i<<" oii"<<endl;
				int atual=s[i]-'0';
				if (i+1<s.size() and (s[i+1]-'0'>=0 and s[i+1]-'0'<10)){
					p++;
					atual*=10;
					atual+=s[i+1]-'0';
					if (i+2<s.size() and (s[i+2]-'0'>=0 and s[i+2]-'0'<10)){
						p++;
						atual*=10;
						atual+=s[i+2]-'0';
					}
				}

				cont++;
				if (cont%2==0){
					g.push_back(make_pair(passado,atual));
				}

				else{
					if (last=='-') passado=atual*acumulado*-1;
					else passado=atual*acumulado;
				}
			}

			else if (s[i]=='('){
				if (last=='-'){
					acumulado*=-1;
					pilha.push(-1);
				}
				else{
					pilha.push(1);
				}
				
				last='+';
			}

			else if (s[i]==')'){
				acumulado/=pilha.top();
				pilha.pop();
			}
			
			else if (s[i]!='0')last=s[i];
		
		}
		
		long long mmc=1;
		long long cima=0;
		
		for (int i=0; i<g.size(); i++) mmc=lcm(mmc,abs(g[i].second));
		for (int i=0; i<g.size(); i++) cima+=mmc/g[i].second*g[i].first;
		
		long long k=gcd(abs(cima),mmc);
		cima/=k;
		mmc/=k;
		cout<<cima<<"/"<<mmc<<endl;
		
		
		
	}
 	return 0;
}

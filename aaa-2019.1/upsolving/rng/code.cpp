#include <bits/stdc++.h>
#define mod 1009
#define vi vector<int>
#define mtrx vector<vi>
#define pb push_back
using namespace std;

int expo(int a, int b){
	if(!b)return 1;
	if(b & 1) return a * expo(a, b-1) % mod;
	return expo(a*a%mod, b>>1);
}
vi mul(vi a, int b){
	vi c;
	for(int i = 0; i < a.size(); i++)
		c.pb(a[i] * b % mod);
	return c;
}
vi sub(vi a, vi b){
	vi c;
	for(int i = 0; i < a.size(); i++)
		c.pb((a[i] - b[i] + mod) % mod);
	return c;
}
vi gauss_jordan(mtrx &m){
	int sz = m[0].size();
	for (int i = 0; i < m.size(); i++){
		int divby = expo(m[i][i], mod-2);
		for (int k = i; k < sz; k++)
			m[i][k] = m[i][k] * divby % mod;

		for (int k = i+1; k < m.size(); k++){
			vi sb = mul(m[i], m[k][i]);
			m[k] = sub(m[k], sb);
		}
	}
	vi ans;

	for (int i = m.size()-1; i+1; i--){
		ans.pb(m[i][sz-1]);
		for (int j = i-1; j+1; j--)
			m[j][sz-1] = (m[j][sz-1] - m[j][i] * m[i][sz-1] % mod + mod) % mod;
	}	
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	string s;
	cin >> s;
	const int maxn = 1 << 8;

	int ans[6];
	memset(ans, -1, sizeof ans);
	for (int i = 0; i < maxn; i++){
		int tmp[5];
		for (int j = 0; j < 4; j++)
			tmp[j+1] = 1 + i / (1<<(j<<1)) % 4;

		for (int j = 0; j < 4; j++) {
			int x = j+1;
			int k = 0;
			while(k < 15){
				if (s[k] == '?' || s[k]-'0' == x)
					x = tmp[x];
				else 
					break;
				k++;
			}
			if (k == 15){
				mtrx m;
				for(int i = 0; i < 4; i++){
					m.pb(vi());
					for(int j = 3; j+1; j--)
						m[i].pb(expo(i+1, j));
					
					m[i].pb(tmp[i+1]);
				}

				vi solution = gauss_jordan(m);
				
				for(int i = 0; i < 4; i++)
					ans[i] = solution[i];

				ans[4] = mod;
				ans[5] = j+1;
			}
		}
	}

	for (int i = 0; i < 6; i++)
		cout << ans[i] << " \n"[i==5];

 	return 0;
}
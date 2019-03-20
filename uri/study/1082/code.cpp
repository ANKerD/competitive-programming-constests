#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int p[26];

int find(int x){
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);
	if(a > b) swap(a,b);
	if(a != b)
		p[b] = a;
}

int main(){
	int t;
	cin >> t;
	for(int k = 0; k < t; k++){
		int n,m;
		cin >> n >> m;
		for(int i = 0; i < n; i++) p[i] = i;
		char x,y;
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			join(x-'a', y-'a');
		}
		vector<char> vi[26];
		set<char> sz;
		for(int i = 0; i < n; i++)
			vi[find(i)].pb('a'+i), sz.insert(find(i));
		
		cout << "Case #" << k+1 << ":\n";

		for(auto i = sz.begin(); i != sz.end(); i++){
			for(auto j: vi[*i])
				cout << (char) j << ',';
			cout << '\n';
		}
		cout << (int) sz.size() << " connected components\n\n";
	}
 	return 0;
}

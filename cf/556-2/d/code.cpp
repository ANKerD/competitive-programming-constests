#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 100010
#define prt(a, n) for(int i = 0; i < n; i++) cout << a[i] << " \n"[i+1 == n];

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}



string s;
int n,q;
vector<char> pt[4];
int nx[maxn][30];

void preproccess(){
	for(int i = 0; i < 26; i++)
		nx[n-1][i] = -1;
	for(int i = n-2; i >= 0; i--){
		for(int j = 0; j < 26; j++)
			nx[i][j] = nx[i+1][j];
		nx[i][s[i+1]-'a'] = i+1;
	}
}

bool available[maxn];

vi occupy(int religion){
	vi a;
	
	if(pt[religion].size() == 0) return a;
	int index, id = 1;
	if(s[0] == pt[religion][0])
		index = 0;
	else
		index = nx[0][pt[religion][0]-'a'];

	while(index != -1 && id < pt[religion].size()){
		a.pb(index);
		
		while(index != -1 && !available[index])
			index = nx[index][pt[religion][id]-'a'];
		
		if(index != -1){
			available[index] = false, 
			++id;
		}
	}
	
	return a;
}

bool solve(){
	vi a;
	for(int i = 0; i < 3; i++)
		a.pb(i+1);
	vi used[4];
	do {
		bool ok = true;
		for(int i = 0; i < 3; i++){
			used[i] = occupy(a[i]);
			if(used[i].size() != pt[a[i]].size()){
				ok = false;
				break;
			}
		}

		for(int i = 0; i < 4; i++)
			for(auto u: used[i])
				available[u] = true;

		if(ok) return true;

	} while(next_permutation(a.begin(), a.end()));
	return false;
}

int main(){
	cin >> n >> q >> s;
	preproccess();
	fill(available, available+n, 1);

	for(int i = 0; i < q; i++){
		char op, v;
		int religion;
		cin >> op >> religion;
		if(op == '+'){
			cin >> v;
			pt[religion].pb(v);
		} else {
			pt[religion].pop_back();
		}
		if(solve())
			cout << "YES\n";
		else
			cout << "NO\n";


		// if(i == 7)
		// 	for(int j = 1; j <= 3; j++){
		// 		for (auto u: pt[j])
		// 			cout << u;
		// 		cout << '\n';
		// 	}
	}	
 	return 0;
}


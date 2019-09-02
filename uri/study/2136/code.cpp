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
#define maxn -879879

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

bool cmp(string a, string b) {
	return a.size() > b.size();
}

int main(){
	string a,b;
	vector<string> v,t;	
	while (1) {
		cin >> a;
		if (a == "FIM") break;
		cin >> b;
		if (b == "YES")
			v.push_back(a);
		else
			t.push_back(a);
	}
	stable_sort(v.begin(), v.end(), cmp);
	stable_sort(t.begin(), t.end(), cmp);
	set<string> ans = set<string>(v.begin(), v.end());
	for (auto u: ans)
		trace(u);
	/* */       ans = set<string>(t.begin(), t.end());
	// trace("-- v");
	for (auto u: ans)
		trace(u);
	cout << '\n';
	trace("Amigo do Habay:");
	trace(v[0]);

 	return 0;
}


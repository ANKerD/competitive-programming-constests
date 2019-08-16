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

struct R {
	string nome;
	ld peso, idade, altura;
};

bool cmp(R a, R b) {
	if (a.peso != b.peso) return a.peso > b.peso;
	if (a.idade != b.idade) return a.idade < b.idade;
	if (a.altura != b.altura) return a.altura < b.altura;
	return a.nome < b.nome;
}

int main(){
	int t,n,k;
	cin >> t;
	for (int x = 0; x < t; ++x) {
		string nome;
		ld peso, idade, altura;
		cin >> n >> k;
		vector<R> a;
		for (int i = 0; i < n; ++i) {
			cin >> nome >> peso >> idade >> altura;
			a.push_back({nome, peso, idade, altura});
		}

		sort(a.begin(), a.end(), cmp);
		printf("CENARIO {%d}\n", x+1);
		for (int i = 0; i < k; ++i)
			trace(i+1,'-',a[i].nome);
	}
 	return 0;
}


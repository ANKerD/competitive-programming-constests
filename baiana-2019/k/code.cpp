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

struct Eq {
	int pt, vit, gol;
	string nome;
	Eq(){pt = vit = gol = 0; nome = "pora";};
};

bool cmp(Eq a, Eq b){
	if (a.pt != b.pt)
        return a.pt > b.pt;
    if (a.vit != b.vit)
        return a.vit > b.vit;
    if (a.gol != b.gol)
        return a.gol > b.gol;
    return a.nome < b.nome;
}

int main(){
	map<int, Eq> Eqs;
	map<string, int> go;

	string s,t;
	int id = 1;
	for (int i = 0; i < 4; ++i) {
		cin >> s;
		go[s] = id;
		Eqs[id].nome = s;
		id++;
	}

	int n, x1,x2;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s >> x1 >> t >> x2;
		Eqs[go[s]].gol += x1-x2;
		Eqs[go[t]].gol += x2-x1;
		if (x1 > x2) {
			Eqs[go[s]].pt += 3;
			Eqs[go[s]].vit += 1;
		} else if (x1 < x2) {
			Eqs[go[t]].pt += 3;
			Eqs[go[t]].vit += 1;
		} else {
			Eqs[go[s]].pt += 1;
			Eqs[go[t]].pt += 1;
		}
	}

	vector<Eq> est;
	for (auto it = Eqs.begin(); it != Eqs.end(); ++it) {
		// trace(it->se.nome);
		est.pb(it->se);
	}
	// trace(est.size());
	sort(est.begin(), est.end(), cmp);
	trace(est[0].nome);
	trace(est[1].nome);

 	return 0;
}


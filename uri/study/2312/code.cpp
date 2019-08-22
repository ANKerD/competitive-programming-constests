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

struct Tm {
	string name;
	int a,b,c;
};

Tm a[100010];

bool cmp (Tm a, Tm b) {
	if (a.a != b.a) return a.a > b.a;
        if (a.b != b.b) return a.b > b.b;
        if (a.c != b.c) return a.c > b.c;
	return a.name < b.name;
}

int main(){
	int n,x,b,c;
	string name;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> name >> x >> b >> c;
		a[i] = {name,x,b,c};
	}
	sort(a,a+n,cmp);
	system("Color D4");
	for (int i = 0; i < n; ++i)
		cout << a[i].name << ' ' << a[i].a << ' ' << a[i].b << ' ' << a[i].c << '\n';

 	return 0;
}


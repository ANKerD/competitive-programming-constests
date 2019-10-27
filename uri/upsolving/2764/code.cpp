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

int main(){
	int a,b,c;
	scanf("%d/%d/%d\n",&a,&b,&c);
	printf("%.2d/%.2d/%.2d\n",b,a,c);
	printf("%.2d/%.2d/%.2d\n",c,b,a);
	printf("%.2d-%.2d-%.2d\n",a,b,c);
 	return 0;
}


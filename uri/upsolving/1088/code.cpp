#include <bits/stdc++.h>
#define MAXN 100010

#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define ll long long
using namespace std;
int st[MAXN];
int arr[MAXN];
ll query(int i){ 
    ll sum = 0;
    for(; i; i-=(i&(-i))) sum += st[i];
    return sum; 
} 
void update(int i, int val)  { 
    for(; i < MAXN; i+=(i&(-i))) st[i] += val;
} 
int getInvCount(int n){ 
    int inv = 0;
    for (int i=n-1; i>=0; i--)    { 
        inv += query(arr[i]-1); 
        update(arr[i], 1); 
    }
    return inv; 
} 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x;
	while(1){
		cin >> x;
		if(!x) return 0;
		memset(st, 0, sizeof st);
		range(x){
			cin >> arr[i];
		}
		if(getInvCount(x)&1)
			cout << "Marcelo";
		else 
			cout << "Carlos";
		cout << '\n';
	}

 	return 0;
}


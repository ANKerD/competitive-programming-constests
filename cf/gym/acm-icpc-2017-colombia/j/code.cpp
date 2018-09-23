#include <bits/stdc++.h>
#define maxn 30000101
#define mod 30000000
#define md(x) (x) % mod;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ps push
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF 100000000
#define INFd 100000000.0
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int q, a, b, c, d, fa, fb;
int n, k = 0, m, t;
int li[maxn];
int sortl[maxn];

int main() {
    sc("%d %d %d\n", &n, &m, &q);
	for(int i = 0; i < maxn; i++) {
		sortl[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        sc("%d", li+i);
		sortl[li[i]]++;
    }
	for(int i = m; i < n; i++) {
		li[i] = (li[i-m] + li[i-m+1]) % mod;
		sortl[li[i]]++;
	}
	int i = 0;
	int j = 0;
	while (i < n) {
		while (sortl[j] != 0) {
			li[i] = j;
			sortl[j]--;
			i++;
		}
		j++;
	}
	for(i = 0; i < q; i++) {
        sc("%d", &a);
		pr("%d\n", li[a-1]);
    }
    return 0;
}

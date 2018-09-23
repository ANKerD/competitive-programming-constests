#include <bits/stdc++.h>
#define MAXN 100010

#define trace1(a) cout << a << '\n';
#define printArr(arr, tam) for(int i = 0; i < tam; i++) cout << arr[i] << " \n"[i==tam-1];

using namespace std;

int Z[2*MAXN];
int f[MAXN];

int sz;
char a[MAXN];
char b[MAXN];
char c[2*MAXN+1];
int n = 0, m = 0, p=0;

void zFunction(){
	int left = 0;
	int right = 0;
	Z[0] = 0; // Some invalid random number
	for(int k = 1; k < p; k++) {
		if(k > right) {
			left = right = k;
			while(right < p && c[right] == c[right - left]) {
				right++;
			}
			Z[k] = right - left;
			right--;
		} else {
			//we are operating inside box
			int k1 = k - left;
			//if value does not stretches till right bound then just copy it.
			if(Z[k1] < right - k + 1) {
				Z[k] = Z[k1];
			} else { //otherwise try to see if there are more matches.
				left = k;
				while(right < p && c[right] == c[right - left]) {
					right++;
				}
				Z[k] = right - left;
				right--;
			}
		}
	}
}

int main(){

	char ch = getchar();
	while (ch != '\n') {
		a[n++] = ch;
		ch = getchar();
	}
	ch = getchar();
	while (ch != '\n') {
		b[m++] = ch;
		ch = getchar();
	}
	scanf("%d\n", &sz);
	int i = 0;
	for (i = 0; i < m; i++) {
		c[i] = b[i];
	}
	c[i++] = '#';
	for (int j = 0; j < n; j++) {
		c[i++] = a[j];
	}
	memset(f,0,sizeof f);
	p=i;
	zFunction();
	int cnt=0;
	for(i = m; i <= m+n; i++) f[Z[i]]++;
	for(i = n; i > 0 && cnt < sz; i--) cnt += f[i];
    if(cnt < sz)
    	printf("IMPOSSIBLE\n");
	else {
		for(int j = 0; j <= i; j++)
			cout << b[j];
		cout << '\n';
	}
		
    return 0;
}
#include <bits/stdc++.h>
#define MAXN 100010
#define vi vector<int>

#define trace1(a) cout << a << '\n';
#define printArr(arr, tam) for(int i = 0; i < tam; i++) cout << arr[i] << " \n"[i==tam-1];

using namespace std;

int f[MAXN];

int sz;
string a, b, c;

vi zFunction(string text){
	int left = 0;
	int right = 0;
	vi Z(text.size());
	Z.clear();
	Z[0] = 0; // Some invalid random number
	for(int k = 1; k < text.size(); k++) {
		if(k > right) {
			left = right = k;
			while(right < text.size() && text[right] == text[right - left]) {
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
				while(right < text.size() && text[right] == text[right - left]) {
					right++;
				}
				Z[k] = right - left;
				right--;
			}
		}
	}
	return Z;
}

int main(){

	getline(cin, a);
	getline(cin, b);
	cin >> sz;
	c = b+'$'+a;
	memset(f,0,sizeof f);
	
	vi Z = zFunction(c);
	int cnt=0;
	int i;
	for(i = (int)b.size(); i < c.size(); i++) f[Z[i]]++;
	for(i = (int)a.size(); i > 0 && cnt < sz; i--) cnt += f[i];
    if(cnt < sz)
    	printf("IMPOSSIBLE\n");
	else {
		for(int j = 0; j <= i; j++)
			cout << b[j];
		cout << '\n';
	}
		
    return 0;
}

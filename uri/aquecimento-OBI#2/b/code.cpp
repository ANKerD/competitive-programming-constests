#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  int ga = 0, go = 0;
  int ca = 0, co = 0;
  int n;
  cin >> n;
  while(n--){
    string s;
    cin >> s;
    if(s == "chuva")
      if(ga)
        ga--, go++;
      else
        ca++, go++;
    cin >> s;
    if(s == "chuva")
      if(go)
        go--, ga++;
      else
        co++, ga++;
  }

  cout << ca << ' ' << co << '\n';

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){

  int a,b;
  cin >> a >> b;
  queue<int> bill;
  queue<int> g;
  int x;
  while(a--){
    cin >> x;
    g.push(x);
  }
  while(b--){
    cin >> x;
    bill.push(x);
  }

  int cnt = 0;
  while(!bill.empty() && !g.empty()){
    if(g.front() <= bill.front())
      bill.pop(), cnt++;
    g.pop();

  }

  cout << cnt << '\n';

  return 0;
}

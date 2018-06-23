#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;
// string ins[4][2][2] = {
//   {{"00", "00"}, {"00", "0X"}},
//   {{"00", "00"}, {"00", "X0"}},
//   {{"00", "00"}, {"0X", "00"}},
//   {{"00", "00"}, {"X0", "00"}}
// };
string l[4][2][2] = {
  {{0,0}, {0,1}},
  {{0,0}, {1,0}},
  {{0,1}, {0,0}},
  {{1,0}, {0,0}},
};

bool m[2][100];
bool all[2][2] = {{1,1}, {1,1}};

string a, b;
int cnt = 0;

int answer[100][4];
int sz;

bool solve(int index, int sh, int v = 0){
  if (index+1 == sz)
    return 0;

  if(answer[index][sh] != -1)
    return answer[index][sh];

  bool can = true;
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      if(!l[sh][i][i])
        if(!m[i][j])
          can = false;
  if(can)
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      if(!l[sh][i][i])
        m[i][j] = 0;


  return answer[index][sh] = v;
}

int main(){

  getline(cin, a);
  getline(cin, b);
  sz = a.size();
  memset(answer, -1, sizeof(answer[0])*100*4);

  for(int i = 0; i < a.size(); i++)
    m[0][i] = a[i] == '0'? 1 : 0;

  for(int i = 0; i < a.size(); i++)
    m[1][i] = b[i] == '0'? 1 : 0;

  int ans = 0;
  for(int i = 0; i < 4; i++)
    ans = max(solve(0, i));

  cout << ans << '\n';

  return 0;
}

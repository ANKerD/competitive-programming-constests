#include <bits/stdc++.h>
#define N_MAX 100010
using namespace std;

line q1[4];
line q2[4];

point pq1[4];
point pq2[4];

struct point{
  int x, y;
}

struct line{
  point p1, p2;
}

line newPoint(int x, int y){
  point p;
  p.x = x;
  p.y = y;
  return p;
}
line newLine(point p1, point p2){
  line l;
  line.p1 = p1.
  line.p2 = p2.
  return l;
}

int turn(point p, point q, point r){
  int result = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
  if(result < 0) return -1;
  if(result > 0) return 1;
  return 0;
}

bool ccw(point p, point q, point r){
  return turn(p, q, r) >= 0;
}

bool intersect(line line1, line line2){
  return
    ((ccw(line1.p1, line1.p2, line2.p1) * ccw(line1.p1, line1.p2, line2.p2)) <= 0)
      &&
    ((ccw(line2.p1, line2.p2, line1.p1) * ccw(line2.p1, line2.p2, line1.p2)) <= 0);
}

void readQ(line q[], point p[]){
  int x, y;
  cin >> x >> y;
  point p1 = newPoint(x, y);
  p[0] = p1;

  cin >> x >> y;
  point p1 = newPoint(x, y);
  p[1] = p2;

  cin >> x >> y;
  point p1 = newPoint(x, y);
  p[2] = p3;

  cin >> x >> y;
  point p4 = newPoint(x, y);
  p[3] = p4;
}

int main(){
  ios_base::sync_with_stdio(false);

  int x, 1;


  return 0;
}

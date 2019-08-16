from math import sqrt
while True:
    a,b,c = map(int, raw_input().split())
    if a==0:break
    a = int(pow(a*b*c, 1.0/3))
    print a

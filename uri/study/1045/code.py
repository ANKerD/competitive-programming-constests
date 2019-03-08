eps = .000000001
def cmp(a,b):
	if(abs(a-b) < eps): return 0
	return -1 if a < b else 1

def isoc(a,b,c):
    return a == b and b != c


l = map(float, raw_input().split())
l.sort()
l.reverse()
a,b,c = l
if cmp(a , (b+c))>-1:
    print("NAO FORMA TRIANGULO")
    exit()

if cmp(a*a, b*b+c*c) == 0: print("TRIANGULO RETANGULO")
if cmp(a*a, b*b+c*c)  == 1: print("TRIANGULO OBTUSANGULO")
if cmp(a*a, b*b+c*c)  == -1: print("TRIANGULO ACUTANGULO")
if cmp(a,b) == 0 and cmp(b,c) == 0 and cmp(a,c) == 0:
    print("TRIANGULO EQUILATERO")
if isoc(a,b,c) or isoc(a,c,b) or isoc(b,a,c) or isoc(b,c,a) or isoc(c,a,b) or isoc(c,b,a):
    print("TRIANGULO ISOSCELES")


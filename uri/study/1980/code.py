from collections import defaultdict
from math import factorial

while True:
    try:
        
        a = ''.join(raw_input().split())
        # print a
        if a == '0': 
            break
        x = defaultdict(int)
        ans = factorial(len(a))
        for i in a:
            x[i] +=1
        for i in x.values():
            ans /= max(1,factorial(i))
        print '%d' % ans
        
    except:
        break
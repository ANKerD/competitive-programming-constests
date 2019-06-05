q,w,e = map(int, raw_input().split())
a,s,d = map(int, raw_input().split())

ans = min(0, q-a)+min(0,w-s)+min(0,e-d)
print -ans
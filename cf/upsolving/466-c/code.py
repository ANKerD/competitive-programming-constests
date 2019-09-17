def main():
    n, = read()
    a = read()
    s = sum(a)
    if s%3:
        print(0)
        return
    s //= 3
    t = 0
    ct = 0
    res = 0
    for i in range(n-1):
        t += a[i]
        if t == 2*s:
            res += ct
        if t == s:
            ct += 1
    print(res)
 
################################### NON-SOLUTION STUFF BELOW
 
def read(mode=2):
    # 0: String
    # 1: List of strings
    # 2: List of integers
    inputs = input().strip()
    if mode == 0: return inputs
    if mode == 1: return inputs.split()
    if mode == 2: return list(map(int, inputs.split()))
 
def write(s="\n"):
    if s is None: s = ""
    if isinstance(s, list): s = " ".join(map(str, s))
    s = str(s)
    print(s, end="")
 
write(main())
# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
# n = int(raw_input())

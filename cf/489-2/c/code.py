MOD = 1000000007
def fpow(a, b):
    # a %= 2*MOD
    if(b == 0):
        return 1
    if b % 2 == 1:
        return a * fpow(a, b-1)
    return fpow(a*a, b/2)
n, k = map(int, raw_input().split())
k %= 2*MOD
power = fpow(2, k)

ans = (2*n*power + 1 - power+MOD) % MOD
print "%d" % ans

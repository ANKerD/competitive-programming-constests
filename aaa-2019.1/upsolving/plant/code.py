mod = 1000000007
n = int(raw_input())
ans = (pow(4, n, mod) + pow(2, n, mod)) % mod
ans = ans * pow(2, mod-2, mod) % mod
print ans
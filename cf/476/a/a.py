from math import ceil

k, n, s, p = map(float, raw_input().split())

print '%d' % ceil(ceil(n/s) * k / p)

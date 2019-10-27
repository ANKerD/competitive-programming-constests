a = 'Dasher, Dancer, Prancer, Vixen, Comet, Cupid, Donner, Blitzen, Rudolph'.split(', ')
m = sum(map(int, raw_input().split()))-1
print a[m%len(a)]


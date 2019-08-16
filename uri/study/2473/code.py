m = set.intersection(set(map(int, raw_input().split())), set(map(int, raw_input().split())))
a = {
    3: 'terno',4:'quadra',5:'quina',6:'sena'
}
print a.get(len(m), 'azar')
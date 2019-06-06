import string

a = set()
b = []

while True:
    try:
        c = input()
        # print(c)
        for i in c.split():
            b.append(i.lower())
            for j in i:
                a.add(j.lower())
    except Exception as e:
        # print (e)
        break

b = ' '.join(b)
for i in a:
    if i not in string.ascii_lowercase:
        b = ' '.join(b.split(i))
b = b.split()
for i in sorted(set(b)):
    # print( i == '\n')
    print(i)
print('\n')

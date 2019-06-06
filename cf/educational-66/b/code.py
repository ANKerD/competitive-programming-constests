mx = 2**32

n = int(input())

v = 0
mul = 1
st = []
for i in range(n):
    z = input()
    if z == 'end':
        mul = st[-1]
        st.pop()
    elif z == 'add':
        v += mul
    else:
        a, b = z.split()
        b = int(b)
        st.append(min(mx, mul))
        mul *= b
    if v >= mx:
        print('OVERFLOW!!!')
        exit()

print(v)
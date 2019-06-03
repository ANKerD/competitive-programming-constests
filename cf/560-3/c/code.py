n = int(raw_input())
m = raw_input()
a = []
i = 0
while i < n:
        j = i+1
        while j < n and m[i] == m[j]:
                j += 1
        if j < n:
                a.append(m[i])
                a.append(m[j])
        i = j+1
print n-len(a)
print ''.join(a)
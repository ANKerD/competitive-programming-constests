n = int(raw_input())
for _ in range(n):
    a = raw_input()
    ans = 1
    for i in a:
        if i.lower() in 'aeios43105':
            ans *= 3
        elif not i.isdigit():
            ans *= 2
    print ans
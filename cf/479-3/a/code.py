a = raw_input()

o = 0;
dash = 0;

for i in a:
    if i == '-':
        dash += 1
    else:
        o += 1
if dash == 0 or o == 0:
    print "YES"
    exit()
if dash % o == 0:
    print "YES"
    exit()
print "NO"

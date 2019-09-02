from collections import defaultdict
dead = set()
cnt = defaultdict(int)
while True:
  try:
    a,b = raw_input().split()
    dead.add(b)
    cnt[a] += 1
  except EOFError:
    break
  except Exception as e:
    print e
ans = []
for key, value in cnt.items():
  if not key in dead:
    ans.append((key, value))
ans.sort()
print 'HALL OF MURDERERS'
for key, value in ans:
  print key,value
a = set()
while True:
  try:
    x = raw_input()
    a.add(x)
  except:
    break
print len(a)
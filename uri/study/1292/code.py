while True:
  try:
    a = float(raw_input())
    print '%.10f' % (1.067395681711179 * a,)
  except:
    break
  # except Exception as e:
    # print e
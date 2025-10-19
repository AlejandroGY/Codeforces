t = int(input( ))
for _ in range(t):
  n, k = map(int, input( ).split( ))
  s = input( ).strip( )

  last = -10**9
  res = 0
  for i, char in enumerate(s):
    if char == "1":
      if i - last >= k:
        res += 1
      last = i
  print(res)
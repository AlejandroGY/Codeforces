t = int(input( ))
for _ in range(t):
  n = int(input( ))
  arr = list(map(int, input( ).split( )))
  
  n = len(arr)
  if n == 1:
    print(0)
    continue

  max_left = [0] * n
  for i in range(n):
    max_left[i] = arr[i]
    if i > 0:
      max_left[i] = max(max_left[i], max_left[i - 1])
  
  res = 0
  for i in range(0, n, 2):
    if i == 0:
      target = max_left[1] - 1
    else:
      target = max_left[i - 1] - 1
    
    if arr[i] > target:
      res += arr[i] - target
  print(res)

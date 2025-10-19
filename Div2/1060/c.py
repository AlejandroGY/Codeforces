from collections import defaultdict


def get_sieve(m):
  sieve = list(range(m + 10))
  for i in range(2, int(m ** 0.5) + 1):
    if sieve[i] == i:
      step = i
      for j in range(i * i, m + 1, step):
        if sieve[j] == j:
          sieve[j] = i
  return sieve

def factor_distinct(num, sieve):
  primes = []
  while num > 1:
    prime = sieve[num]
    primes.append(prime)
    while num % prime == 0:
      num //= prime
  
  if not primes:
    return []
  
  factors = [primes[0]]
  for prime in primes[1:]:
    if prime != factors[-1]:
      factors.append(prime)
  return factors

def main( ):
  t = int(input( ))
  for tc in range(t):
    n = int(input( ))
    a = list(map(int, input( ).split( )))
    b = input( )

    maximum = max(a) + 1
    sieve = get_sieve(maximum)

    seen = defaultdict(int)
    primes = []
    zero = False

    for num in a:
      factors = factor_distinct(num, sieve)
      primes.append(set(factors))
      for p in factors:
        seen[p] += 1
        if seen[p] >= 2:
          zero = True
    if zero:
      print(0)
      continue
      
    one = False
    for i, num in enumerate(a):
      factors = factor_distinct(num + 1, sieve)
      prime_set = primes[i]
      for p in factors:
        if (p not in prime_set and seen[p] >= 1) or (seen[p] >= 2):
          one = True
          break
      if one:
        break
    if one:
      print(1)
    else:
      print(2)

  
if __name__ == "__main__":
  main( )
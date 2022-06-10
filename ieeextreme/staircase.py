t = int(input() )

memo = {}

def f(n):
	if(n <= 2):return n
	if(n in memo):return memo[n]
	memo[n] = f(n - 1) + f(n - 2)
	return memo[n] 

for _ in range(t):
	n = int(input() )
	print(f(n) )
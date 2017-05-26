#Nth fibonacci number (Dynamic Programming with memoization)

lookup = [None] * 100
def fib(n):
	if(n == 1 or n == 2):
		lookup[n - 1] = n - 1
	else:
		if(lookup[n - 1] == None):
			lookup[n - 1] = fib(n - 1) + fib(n - 2)
	return lookup[n - 1]

def main():
	x = int(input("Input the value of n: "))
	print("Nth fibonacci number is:", fib(x))

if __name__ == "__main__":
	main()
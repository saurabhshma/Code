#Nth fibonacci number (Dynamic Programming with tabulation)

lookup = [None] * 100
def fib(n):
	if(n == 1 or n == 2):
		lookup[n - 1] = n - 1
	else:
		lookup[0] = 0
		lookup[1] = 1
		for i in range(2, n):
			lookup[i] = lookup[i - 1] + lookup[i - 2]
	return (lookup[n - 1])

def main():
	x = int(input("Input the value of n: "))
	print("Nth fibonacci number is:", fib(x))

if __name__ == "__main__":
	main()
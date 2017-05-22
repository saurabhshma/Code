#http://www.practice.geeksforgeeks.org/problem-page.php?pid=667

t = int(raw_input())
for i in range(t):
	table = {}
	flag = 0
	n, p = raw_input().split()
	n = int(n)
	p = int(p)
	a = [int(x) for x in raw_input().split()]
	for index in range(n):
		table[a[index]] = True
	for index in range(n):
		if p % a[index] == 0:
			print p % a[index]
			temp = p / a[index]
			print temp
			if(table.has_key(temp)):
				if(table[temp] == True):
					print "Yes"
					flag = 1
					break
	if flag == 0:
		print "No"
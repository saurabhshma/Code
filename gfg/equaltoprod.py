#http://www.practice.geeksforgeeks.org/problem-page.php?pid=667

t = int(raw_input())
for i in range(t):
	flag = 0
	n, p = raw_input().split()
	n = int(n)
	p = int(p)
	a = [int(x) for x in raw_input().split()]
	for j in range(n):
		for k in range(j + 1, n):
			if a[k] * a[j] == p:
				print "Yes"
				flag = 1
				break
		if flag == 1:
			break
	if flag == 0:
		print "No"
#https://www.hackerrank.com/challenges/birthday-cake-candles
n = int(input())
tempMax = -1
count = 0
tempInput = input()
for i in tempInput.strip().split(' '):
	temp = int(i)
	if(temp > tempMax):
		count = 1
		tempMax = temp
	elif(temp == tempMax):
		count = count + 1
print(count)
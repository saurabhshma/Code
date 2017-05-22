#https://www.hackerrank.com/challenges/birthday-cake-candles
inputData = list(map(int, input().strip().split(' ')))
sumData = sum(inputData)
minData = min(inputData)
maxData = max(inputData)
print((sumData - maxData), (sumData - minData))
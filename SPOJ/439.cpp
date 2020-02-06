import sys
numbers = input()
numbers = int(numbers)
n=0
while n<numbers:
	n+=1
	a, b = input().split()
	a = int(a)
	b = int(b)
	c = a*b
	print(c)
